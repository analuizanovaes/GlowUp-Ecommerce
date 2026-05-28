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
    scanf(" %[^\n]", novo.nome);

    printf("Idade: ");
    scanf("%d", &novo.idade);

    while (getchar() != '\n');

    if (novo.idade < 16)
    {
        printf("Idade minima e 16 anos\n");
        return;
    }

    printf("CPF: ");
    scanf("%s", novo.cpf);

    if (cpfExiste(novo.cpf))
    {
        printf("CPF ja existe\n");
        return;
    }

    printf("Email: ");
    scanf("%s", novo.email);

    if (emailExiste(novo.email))
    {
        printf("Email ja existe\n");
        return;
    }

    printf("Senha: ");
    scanf("%s", novo.senha);

    printf("Endereco: ");
    scanf(" %[^\n]", novo.endereco);

    printf("Telefone: ");
    scanf("%s", novo.telefone);

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
        scanf("%s", email);

        printf("Senha: ");
        scanf("%s", senha);

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
    scanf(" %[^\n]", usuarios[indice].endereco);
    while (getchar() != '\n'); 

    printf("Novo telefone: ");
    scanf("%s", usuarios[indice].telefone);

    printf("Novo email: ");
    scanf("%s", usuarios[indice].email);

    printf("Nova senha: ");
    scanf("%s", usuarios[indice].senha);

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