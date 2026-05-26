#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Definição do perfil de usuário
typedef struct {
    int id;
    char nome[100];
    char cpf[15];
    char email[100];
    char senha[50];
    char endereco[200];
} Usuario;

// Definição do produto no catálogo
typedef struct {
    int id;
    char nome[100];
    char categoria[50];
    float preco;
    int estoque;
} Produto;

// Estrutura para os itens dentro de um carrinho
typedef struct {
    int id_produto;
    int quantidade;
    float subtotal;
} ItemCarrinho;

// Registro final do pedido após o checkout
typedef struct {
    int id_pedido;
    int id_usuario;
    float total;
    char status[20];
} Pedido;

// Registro de avaliação do pós-venda
typedef struct {
    int id_pedido;
    int nota;
    char comentario[100];
} Avaliacao;

// Variáveis globais (Mock de Dados) acessíveis por todos os arquivos
extern Usuario usuarios[100];
extern int total_usuarios;

extern Produto catalogo[50];
extern int total_produtos;

extern Pedido pedidos[100];
extern int total_pedidos;

#endif