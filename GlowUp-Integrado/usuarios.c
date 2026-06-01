#include <stdio.h>
#include <string.h>
#include "usuarios.h"
#include "variaveis_globais.h"

int cpfExiste(char cpf[])
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(cpf, usuarios[i].cpf) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int emailExiste(char email[])
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(email, usuarios[i].email) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void cadastrarUsuario()
{
    if (totalUsuarios >= MAX)
    {
        printf("Limite atingido\n");
        return;
    }

    Usuario novo;

    printf("\nNome: ");
    scanf(" %99[^\n]", novo.nome);
    while (getchar() != '\n');

    printf("Idade: ");
    if (scanf("%d", &novo.idade) != 1)
    {
        printf(">> Erro: Entrada invalida. Digite apenas numeros.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n');

    printf("CPF: ");
    scanf("%14s", novo.cpf);
    while (getchar() != '\n'); 

    if (cpfExiste(novo.cpf))
    {
        printf("CPF ja existe\n");
        return;
    }

    printf("Email: ");
    scanf("%99s", novo.email);
    while (getchar() != '\n')
        ; // Limpa o buffer

    if (emailExiste(novo.email))
    {
        printf("Email ja existe\n");
        return;
    }

    printf("Senha: ");
    scanf("%49s", novo.senha);
    while (getchar() != '\n')
        ; // Limpa o buffer

    printf("Endereco: ");
    scanf(" %199[^\n]", novo.endereco);
    while (getchar() != '\n')
        ; // Limpa o buffer

    printf("Telefone: ");
    scanf("%19s", novo.telefone);
    while (getchar() != '\n')
        ; // Limpa o buffer

    novo.bloqueado = 0;

    usuarios[totalUsuarios] = novo;
    totalUsuarios++;

    printf("Usuario cadastrado\n");
}

int realizarLogin()
{
    char email[50];
    char senha[20];
    int tentativas = 0;

    while (tentativas < MAX_TENTATIVAS)
    {
        printf("\nEmail: ");
        scanf("%49s", email);

        printf("Senha: ");
        scanf("%19s", senha);

        for (int i = 0; i < totalUsuarios; i++)
        {
            if (strcmp(email, usuarios[i].email) == 0)
            {
                if (usuarios[i].bloqueado)
                {
                    printf("Conta bloqueada\n");
                    return -1;
                }

                if (strcmp(senha, usuarios[i].senha) == 0)
                {
                    printf("Login realizado\n");
                    return i;
                }
            }
        }
        tentativas++;
        printf("Dados incorretos\n");
    }

    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(email, usuarios[i].email) == 0)
        {
            usuarios[i].bloqueado = 1;
        }
    }
    return -1;
}

void editarDados(int indice)
{
    if (indice == -1)
    {
        printf("Faca login primeiro\n");
        return;
    }

    printf("\nNovo endereco: ");
    scanf(" %199[^\n]", usuarios[indice].endereco);
    while (getchar() != '\n')
        ;

    printf("Novo telefone: ");
    scanf("%19s", usuarios[indice].telefone);

    printf("Novo email: ");
    scanf("%99s", usuarios[indice].email);

    printf("Nova senha: ");
    scanf("%49s", usuarios[indice].senha);

    printf("\n>> Dados atualizados com sucesso!\n");
    printf(">> (Lembre-se: os dados nao sao salvos se voce fechar o terminal!)\n");
}

void listarUsuarios()
{
    for (int i = 0; i < totalUsuarios; i++)
    {
        printf("\nIndice: %d", i);
        printf("\nNome: %s", usuarios[i].nome);
        printf("\nEmail: %s", usuarios[i].email);
        printf("\nCPF: %s\n", usuarios[i].cpf);
    }
}
