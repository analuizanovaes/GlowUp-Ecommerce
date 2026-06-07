#ifndef USUARIOS_H
#define USUARIOS_H


#define MAX 10
#define MAX_TENTATIVAS 3



typedef struct {

    char nome[50];
    int idade;
    char cpf[15];
    char email[50];
    char senha[20];
    char endereco[100];
    char telefone[20];

    int bloqueado;

} Usuario;



extern Usuario usuarios[MAX];
extern int totalUsuarios;




int validarNome(char nome[]);
int validarIdadeEntrada(char idade[]);
int validarIdade(int idade);
int validarCPF(char cpf[]);
int validarEmail(char email[]);
int validarEndereco(char endereco[]);
int validarTelefone(char telefone[]);



void cadastrarUsuario();



int realizarLogin();



void editarDados(int indice);



void listarUsuarios();



#endif
