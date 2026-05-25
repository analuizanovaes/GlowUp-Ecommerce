#ifndef USUARIOS_H
#define USUARIOS_H


//maximo de usuarios
#define MAX 10

// maximo de tentativas
#define MAX_TENTATIVAS 3


typedef struct {

    char nome[50];
    int idade;
    char cpf[15];
    char email[50];
    char senha[20];
    char endereco[100];
    char telefone[20];

    //indica se a conta está bloqueada
    int bloqueado;

} Usuario;



extern Usuario usuarios[MAX];
extern int totalUsuarios;



int cpfExiste(char cpf[]);
int emailExiste(char email[]);

void cadastrarUsuario();

int realizarLogin();

void editarDados(int indice);

void listarUsuarios();

#endif