#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "usuarios.h"



Usuario usuarios[MAX];

int totalUsuarios = 0;



//===========================
// VALIDA NOME CT-04
//===========================

int validarNome(char nome[]){

    for(int i=0;i<strlen(nome);i++){


        if(!isalpha(nome[i]) &&
           nome[i]!=' '){


            printf(
            "\nCaractere invalido, o nome e composto de letras\n");


            return 0;
        }
    }


    return 1;
}




//validacao de idade

int validarIdadeEntrada(char idade[]){


    for(int i=0;i<strlen(idade);i++){


        if(!isdigit(idade[i])){


            printf(
            "\nCaractere invalido, o campo idade e exclusivamente de numeros\n");


            return 0;
        }

    }


    return 1;
}




//limite de idade

int validarIdade(int idade){


    if(idade < 16){


        printf(
        "\nIdade minima permitida: 16 anos\n");


        return 0;

    }



    if(idade > 125){


        printf(
        "\nA idade cadastrada e improvavel\n");


        return 0;

    }



    return 1;
}





//cpf

int validarCPF(char cpf[]){


    if(strlen(cpf)!=11){


        printf(
        "\nCaractere invalido, CPF deve ter 11 numeros\n");


        return 0;

    }



    for(int i=0;i<strlen(cpf);i++){


        if(!isdigit(cpf[i])){


            printf(
            "\nCaractere invalido, CPF possui somente numeros\n");


            return 0;

        }

    }


    return 1;
}




//email

int validarEmail(char email[]){


    if(strchr(email,'@')==NULL ||
       strstr(email,".com")==NULL){


        printf(
        "\nCaractere invalido, e-mail deve seguir usuario@empresa.com\n");


        return 0;

    }


    return 1;

}





//endereço

int validarEndereco(char endereco[]){


    if(strstr(endereco,"Rua")==NULL ||
       strchr(endereco,',')==NULL){


        printf(
        "\nCaractere invalido, endereco deve ser: Rua X, 123, Proximo a Y\n");


        return 0;

    }


    return 1;

}





//telefone

int validarTelefone(char telefone[]){


    int tamanho=strlen(telefone);



    if(tamanho < 11 || tamanho > 15){


        printf(
        "\nTelefone deve possuir 11 a 15 caracteres numericos\n");


        return 0;

    }




    for(int i=0;i<tamanho;i++){


        if(!isdigit(telefone[i]) &&
           telefone[i]!='-'){


            printf(
            "\nCaractere invalido no telefone\n");


            return 0;

        }

    }


    return 1;

}





//repetiçao cpf

int cpfExiste(char cpf[]){


    for(int i=0;i<totalUsuarios;i++){


        if(strcmp(cpf,usuarios[i].cpf)==0)

            return 1;

    }


    return 0;
}





//repeticao email

int emailExiste(char email[]){


    for(int i=0;i<totalUsuarios;i++){


        if(strcmp(email,usuarios[i].email)==0)

            return 1;

    }


    return 0;

}







//cadastro nome

void cadastrarNome(char nome[]){


    while(1){


        printf("\nNome: ");

        scanf(" %[^\n]",nome);



        if(validarNome(nome))

            break;

    }

}





//cadastro idade

int cadastrarIdade(){


    char texto[10];

    int idade;



    while(1){


        printf("\nIdade: ");

        scanf("%s",texto);



        if(!validarIdadeEntrada(texto))

            continue;




        idade=atoi(texto);



        if(validarIdade(idade))

            return idade;

    }

}





//cadastro cpf

void cadastrarCPF(char cpf[]){


    while(1){


        printf("\nCPF: ");

        scanf("%s",cpf);



        if(!validarCPF(cpf))

            continue;



        if(cpfExiste(cpf)){


            printf("CPF ja cadastrado\n");

            continue;

        }


        break;

    }

}






//cadastro email

void cadastrarEmail(char email[]){


    while(1){


        printf("\nEmail: ");

        scanf("%s",email);



        if(!validarEmail(email))

            continue;




        if(emailExiste(email)){


            printf("Email ja cadastrado\n");

            continue;

        }


        break;

    }

}







//cadastro endereço

void cadastrarEndereco(char endereco[]){


    while(1){


        printf("\nEndereco: ");

        scanf(" %[^\n]",endereco);



        if(validarEndereco(endereco))

            break;

    }

}






//cadastro telefone

void cadastrarTelefone(char telefone[]){


    while(1){


        printf("\nTelefone: ");

        scanf("%s",telefone);



        if(validarTelefone(telefone))

            break;

    }

}








void cadastrarUsuario(){


    Usuario novo;



    if(totalUsuarios>=MAX){


        printf("Limite atingido\n");

        return;

    }




    printf("\n===== CADASTRO =====\n");



    cadastrarNome(novo.nome);



    novo.idade=cadastrarIdade();



    cadastrarCPF(novo.cpf);



    cadastrarEmail(novo.email);




    printf("\nSenha: ");

    scanf("%s",novo.senha);




    cadastrarEndereco(novo.endereco);



    cadastrarTelefone(novo.telefone);



    novo.bloqueado=0;




    usuarios[totalUsuarios]=novo;


    totalUsuarios++;




    printf("\nCadastro realizado com sucesso!\n");

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



            if(strcmp(email,usuarios[i].email)==0){



                if(usuarios[i].bloqueado)

                    return -1;




                if(strcmp(senha,usuarios[i].senha)==0)

                    return i;

            }

        }



        tentativas++;

        printf("Dados incorretos\n");

    }


    return -1;

}







//ediçao de cadastro

void editarDados(int indice){



    if(indice==-1){

        printf("Faça login primeiro\n");

        return;

    }



    printf("Novo endereco: ");

    scanf(" %[^\n]",usuarios[indice].endereco);



    printf("Novo telefone: ");

    scanf("%s",usuarios[indice].telefone);



    printf("Novo email: ");

    scanf("%s",usuarios[indice].email);



    printf("Nova senha: ");

    scanf("%s",usuarios[indice].senha);



}







//lista

void listarUsuarios(){


    for(int i=0;i<totalUsuarios;i++){


        printf("\nIndice: %d",i);

        printf("\nNome: %s",usuarios[i].nome);

        printf("\nEmail: %s",usuarios[i].email);

        printf("\nCPF: %s\n",usuarios[i].cpf);

    }

}
