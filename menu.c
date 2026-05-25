#include <stdio.h>
#include "usuarios.h"


int main(){

    int opcao;

    int usuarioLogado=-1;


    do{

        printf("\n=====MENU=====");

        printf("\n1-Cadastrar");
        printf("\n2-Login");
        printf("\n3-Editar Dados");
        printf("\n4-Listar");
        printf("\n0-Sair");

        printf("\nOpcao: ");
        scanf("%d",&opcao);


        switch(opcao){

            case 1:

                cadastrarUsuario();

                break;


            case 2:

                usuarioLogado=
                realizarLogin();


                if(usuarioLogado!=-1){

                    printf(
                    "\nUsuario logado: %d\n",
                    usuarioLogado);

                }

                break;


            case 3:

                editarDados(
                usuarioLogado);

                break;


            case 4:

                listarUsuarios();

                break;


            case 0:

                printf(
                "\nEncerrando");

                break;


            default:

                printf(
                "\nOpcao invalida");

        }

    }while(opcao!=0);


    return 0;

}