// ============================================================================
// ARQUIVO: usuarios.c
// DESCRIÇÃO: Aqui fica o código que faz o cadastro dos clientes, testa
//            o e-mail e a senha no login, e deixa o usuário trocar de senha.
//            Tem várias travas de segurança para o sistema não quebrar.
// ============================================================================

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "usuarios.h"
#include "variaveis_globais.h"

// Confere se alguém já usou esse CPF antes, para não deixar fazer duas contas iguais
int cpfJaCadastrado(char cpf[])
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(cpf, usuarios[i].cpf) == 0)
            return 1;
    }
    return 0;
}

// Olha letra por letra para ver se o usuário digitou apenas números de verdade
int eh_apenas_numeros(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Confere se o e-mail que estão tentando cadastrar já existe no nosso sistema
int emailJaCadastrado(char email[])
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(email, usuarios[i].email) == 0)
            return 1;
    }
    return 0;
}

// ============================================================================
// BLOCO DE VERIFICAÇÕES (Regras para aceitar os dados)
// ============================================================================

// Garante que o nome só tenha letras e espaços (sem números ou símbolos estranhos)
int validarNome(char nome[])
{
    for (int i = 0; i < strlen(nome); i++)
    {
        if (!isalpha(nome[i]) && nome[i] != ' ')
        {
            printf("\n>> Erro: O nome deve conter apenas letras.\n");
            return 0;
        }
    }
    return 1;
}

// Confere se a pessoa não digitou texto no campo de idade (ex: "vinte" em vez de "20")
int validarIdadeEntrada(char idade[])
{
    for (int i = 0; i < strlen(idade); i++)
    {
        if (!isdigit(idade[i]))
        {
            printf("\n>> Erro: A idade deve ser um numero inteiro.\n");
            return 0;
        }
    }
    return 1;
}

// Só deixa comprar quem tem idade para isso (entre 16 e 125 anos)
int validarIdade(int idade)
{
    if (idade < 16 || idade > 125)
    {
        printf("\n>> Erro: Idade fora da faixa permitida (16 a 125 anos).\n");
        return 0;
    }
    return 1;
}

// Confere se o CPF tem o tamanho certo e se só tem números
int validarCPF(char cpf[])
{
    int len = strlen(cpf);

    // 1. Vê se tudo é número para não dar erro misturando com letra
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(cpf[i]))
        {
            printf(">> Erro: O CPF deve conter apenas numeros.\n");
            return 0;
        }
    }

    // 2. Vê se tem exatamente os 11 números padrão do CPF
    if (len != 11)
    {
        printf(">> Erro: O CPF deve ter exatamente 11 numeros.\n");
        return 0;
    }

    return 1; // Tudo certo!
}

// Confere se o e-mail tem o "@" e o ".com" para ser válido
int validarEmail(char email[])
{
    if (strchr(email, '@') == NULL || strstr(email, ".com") == NULL)
        return 0;
    return 1;
}

// Deixa a senha bem forte, exigindo letra grande, pequena, número e símbolo especial
int validarSenha(char senha[])
{
    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0, temEspecial = 0;
    int tamanho = strlen(senha);

    if (tamanho < 8)
    {
        printf(">> Erro: A senha deve ter no minimo 8 caracteres.\n");
        return 0;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (isupper(senha[i]))
            temMaiuscula = 1;
        else if (islower(senha[i]))
            temMinuscula = 1;
        else if (isdigit(senha[i]))
            temNumero = 1;
        else
            temEspecial = 1; // Tudo que não for letra ou número vira especial
    }

    if (!temMaiuscula || !temMinuscula || !temNumero || !temEspecial)
    {
        printf(">> Erro: A senha deve conter maiusculas, minusculas, numeros e especiais.\n");
        return 0;
    }
    return 1;
}

// Garante que o endereço faz sentido para a gente conseguir entregar
int validarEndereco(char endereco[])
{
    int tem_rua =
        (strstr(endereco, "Rua") != NULL ||
         strstr(endereco, "rua") != NULL);

    int tem_brasil =
        (strstr(endereco, "Brasil") != NULL ||
         strstr(endereco, "brasil") != NULL);

    int virgulas = 0;

    for (int i = 0; endereco[i] != '\0'; i++)
    {
        if (endereco[i] == ',')
            virgulas++;
    }

    // Só aceita se tiver a palavra Rua, Brasil e pelo menos duas vírgulas dividindo
    return (tem_rua && tem_brasil && virgulas >= 2);
}

// Verifica se o telefone só tem números e o tamanho mínimo
int validarTelefone(char telefone[])
{
    int len = strlen(telefone);

    // 1. Só aceita números
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(telefone[i]))
        {
            printf(">> Erro: O telefone deve conter apenas numeros.\n");
            return 0; 
        }
    }

    // 2. Vê se o tamanho está certo (com o DDD)
    if (len < 11)
    {
        printf(">> Erro: O telefone deve ter pelo menos 11 digitos.\n");
        return 0;
    }

    return 1;
}

// ============================================================================
// PARTE DO CADASTRO (Com proteção para o programa não travar se o usuário digitar algo muito grande)
// ============================================================================

// Pede o nome do cliente em um loop até ele digitar do jeito certo
void cadastrarNome(char nome[])
{
    while (1)
    {
        printf("\nNome: ");
        scanf(" %99[^\n]", nome); 
        
        // Limpa a "sujeira" do teclado caso a pessoa digite mais coisas que o espaço que temos
        while (getchar() != '\n')
            ; 
        if (validarNome(nome))
            break;
    }
}

// Pede a idade e transforma o texto digitado em um número matemático de verdade
int cadastrarIdade()
{
    char texto[10];
    while (1)
    {
        printf("Idade: ");
        scanf("%9s", texto);
        while (getchar() != '\n')
            ;
        if (validarIdadeEntrada(texto) && validarIdade(atoi(texto)))
            return atoi(texto); // Converte para int com a função atoi
    }
}

// Função grandona que junta todos os dados e cria a conta nova
void cadastrarUsuario()
{
    // Verifica se ainda tem espaço no sistema para colocar clientes
    if (totalUsuarios >= MAX)
    {
        printf(">> Erro: Limite do sistema atingido.\n");
        return;
    }

    Usuario novo;
    cadastrarNome(novo.nome);
    novo.idade = cadastrarIdade();

    // Fica pedindo a senha até o cliente criar uma forte de verdade
    while (1)
    {
        printf("Senha (Min. 8 caracteres, com maiusculas, minusculas, numeros e especiais): ");
        scanf("%49s", novo.senha);
        while (getchar() != '\n')
            ;
        if (validarSenha(novo.senha))
            break;
    }

    // Pede e-mail e já vê se não está em uso
    while (1)
    {
        printf("Email: ");
        scanf("%99s", novo.email);
        while (getchar() != '\n')
            ;
        if (validarEmail(novo.email) && !emailJaCadastrado(novo.email))
            break;
        printf(">> Erro: Email invalido ou ja cadastrado.\n");
    }

    char cpf_temp[20];
    while (1)
    {
        printf("CPF (Apenas numeros): ");
        scanf("%19s", cpf_temp);
        while (getchar() != '\n')
            ;

        if (validarCPF(cpf_temp))
        {
            strcpy(novo.cpf, cpf_temp);
            break;
        }
    }

    while (1)
    {
        printf("Endereco (Ex: Rua X, Cidade, Brasil): ");
        scanf(" %199[^\n]", novo.endereco);
        while (getchar() != '\n')
            ;

        if (validarEndereco(novo.endereco))
            break;
        printf(">> Erro: Formato invalido. Use 'Rua X, Cidade, Brasil'.\n");
    }

    while (1)
    {
        printf("Telefone: ");
        scanf("%19s", novo.telefone);
        while (getchar() != '\n')
            ;

        if (validarTelefone(novo.telefone))
            break;
    }

    novo.bloqueado = 0; // A conta nasce liberada para uso
    novo.id = totalUsuarios + 1; // gerar ID do usuário
    usuarios[totalUsuarios] = novo; // Coloca a pessoa na nossa lista final
    totalUsuarios++;
    printf("\n>> Cadastro realizado com sucesso!\n");
}

// ============================================================================
// PARTE DO LOGIN E DE EDITAR O PERFIL
// ============================================================================

// Confere o e-mail e a senha na hora de entrar no sistema
int realizarLogin()
{
    char email[50], senha[20];
    int tentativas = 0;

    // Fica testando até acertar ou a pessoa acabar com as 3 tentativas
    while (tentativas < MAX_TENTATIVAS)
    {
        printf("\nEmail: ");
        scanf("%49s", email);
        while (getchar() != '\n')
            ;
        printf("Senha: ");
        scanf("%19s", senha);
        while (getchar() != '\n')
            ;

        for (int i = 0; i < totalUsuarios; i++)
        {
            // Achou o email na lista?
            if (strcmp(email, usuarios[i].email) == 0)
            {
                // Vê se a conta não está travada por ter errado muitas vezes no passado
                if (usuarios[i].bloqueado)
                {
                    printf(">> Conta bloqueada por excesso de tentativas.\n");
                    return -1;
                }
                // Senha bateu? Se sim, entra!
                if (strcmp(senha, usuarios[i].senha) == 0)
                    return i;
            }
        }
        tentativas++;
        printf(">> Dados incorretos. Tentativa %d de %d.\n", tentativas, MAX_TENTATIVAS);
    }

    // Se errou as 3 vezes, trava a conta
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(email, usuarios[i].email) == 0)
            usuarios[i].bloqueado = 1;
    }
    return -1;
}

// Deixa o cliente atualizar a rua dele e trocar de senha se quiser
void editarDados(int indice)
{
    if (indice == -1)
        return; // Só por segurança: não edita nada se a pessoa não estiver logada

    char novoEndereco[200];
    char novaSenha[50];

    printf("\n=================================================\n");
    printf("|                 EDITAR PERFIL                 |\n");
    printf("=================================================\n");

    while (1)
    {
        printf("Novo endereco (Ex: Rua X, Cidade, Brasil): ");
        scanf(" %199[^\n]", novoEndereco);

        while (getchar() != '\n')
            ;

        // Vê se o endereço tem Rua, vírgulas e Brasil
        if (!validarEndereco(novoEndereco))
        {
            printf(">> Erro: Formato invalido. Use: Rua X, Cidade, Brasil.\n");
            continue;
        }

        // Não deixa trocar pelo mesmo endereço que já estava
        if (strcmp(novoEndereco, usuarios[indice].endereco) == 0)
        {
            printf(">> Erro: O novo endereco deve ser diferente do atual.\n");
            continue;
        }

        break;
    }

    while (1)
    {
        printf("Nova senha: ");
        scanf("%49s", novaSenha);

        while (getchar() != '\n')
            ;

        if (!validarSenha(novaSenha))
            continue;

        // Não deixa botar a mesma senha antiga
        if (strcmp(novaSenha, usuarios[indice].senha) == 0)
        {
            printf(">> Erro: A nova senha deve ser diferente da atual.\n");
            continue;
        }

        break;
    }

    // Copia os dados novos por cima dos velhos lá na nossa lista
    strcpy(usuarios[indice].endereco, novoEndereco);
    strcpy(usuarios[indice].senha, novaSenha);

    printf("\n=================================================\n");
    printf("|      DADOS ATUALIZADOS COM SUCESSO!           |\n");
    printf("=================================================\n");
}