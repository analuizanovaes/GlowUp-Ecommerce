#include <stdio.h>
#include <string.h>
#include "usuarios.h"


Usuario usuarios[MAX];

//armazena quantidade de usuarios
int totalUsuarios=0;



//verifica do cpf
int cpfExiste(char cpf[]){

    //verifica todos usuários
    for(int i=0;i<totalUsuarios;i++){


        if(strcmp(cpf,usuarios[i].cpf)==0){

            return 1;
        }

    }

    return 0;
}



//verifica o email
int emailExiste(char email[]){

    for(int i=0;i<totalUsuarios;i++){

        if(strcmp(email,
                  usuarios[i].email)==0){

            return 1;
        }

    }

    return 0;
}



//cadastro do usuario
void cadastrarUsuario(){

    if(totalUsuarios>=MAX){

        printf("Limite atingido\n");
        return;
    }

    Usuario novo;

    printf("\nNome: ");
    scanf(" %[^\n]",novo.nome);

    printf("Idade: ");
    scanf("%d",&novo.idade);

    // verifica a idade
    if(novo.idade<16){

        printf("Menor de 16 anos\n");

        return;
    }


    printf("CPF: ");
    scanf("%s",novo.cpf);


    if(cpfExiste(novo.cpf)){

        printf("CPF ja existe\n");

        return;
    }


    printf("Email: ");
    scanf("%s",novo.email);


    // verifica se o email ja existe no sistema
    if(emailExiste(novo.email)){

        printf("Email ja existe\n");

        return;
    }


    printf("Senha: ");
    scanf("%s",novo.senha);


    printf("Endereco: ");
    scanf(" %[^\n]",
            novo.endereco);


    printf("Telefone: ");
    scanf("%s",
            novo.telefone);


    novo.bloqueado=0;


    usuarios[totalUsuarios]=novo;

    totalUsuarios++;


    printf("Usuario cadastrado\n");

}



//login
int realizarLogin(){

    char email[50];
    char senha[20];

    int tentativas=0;


    while(tentativas<MAX_TENTATIVAS){

        printf("\nEmail: ");
        scanf("%s",email);

        printf("Senha: ");
        scanf("%s",senha);


        for(int i=0;i<totalUsuarios;i++){

            if(strcmp(email,
                      usuarios[i].email)==0){

                if(usuarios[i].bloqueado){

                    printf(
                    "Conta bloqueada\n");

                    return -1;
                }

                if(strcmp(senha,
                          usuarios[i].senha)==0){

                    printf(
                    "Login realizado\n");

                    return i;
                }

            }

        }

        tentativas++;

        printf("Dados incorretos\n");

    }

    for(int i=0;i<totalUsuarios;i++){

        if(strcmp(email,
                  usuarios[i].email)==0){

            usuarios[i].bloqueado=1;

        }

    }

    return -1;

}



//editar cadastro
void editarDados(int indice){

    if(indice==-1){

        printf(
        "Faça login primeiro\n");

        return;
    }


    printf(
    "\nNovo endereco: ");

    scanf(
    " %[^\n]",
    usuarios[indice].endereco);


    printf(
    "Novo telefone: ");

    scanf(
    "%s",
    usuarios[indice].telefone);


    printf(
    "Novo email: ");

    scanf(
    "%s",
    usuarios[indice].email);


    printf(
    "Nova senha: ");

    scanf(
    "%s",
    usuarios[indice].senha);


    printf(
    "Dados atualizados\n");

}



//lista de usuarios
void listarUsuarios(){

    for(int i=0;i<totalUsuarios;i++){

        printf(
        "\nIndice: %d",i);

        printf(
        "\nNome: %s",
        usuarios[i].nome);

        printf(
        "\nEmail: %s",
        usuarios[i].email);

        printf(
        "\nCPF: %s\n",
        usuarios[i].cpf);

    }

}