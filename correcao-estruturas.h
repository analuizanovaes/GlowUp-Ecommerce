#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// =======================================================================
// Definição das estruturas de dados globais do sistema
// =======================================================================

// Definição do perfil de usuário (Quem compra)
typedef struct {
    int id;
    char nome[100];
    char cpf[15];
    char email[100];
    char senha[50];
    
    // Campos de endereço divididos para fins de validação logística
    char logradouro[100]; 
    char numero[10];      
    char cidade[50];      
    char uf[3];           
} Usuario;

// Definição do produto no catálogo (O que é vendido)
typedef struct {
    int id;
    char nome[100];
    char categoria[50];
    float preco;
    int estoque;
} Produto;

// Estrutura para os itens dentro de um carrinho (O item temporário)
typedef struct {
    int id_produto;
    int quantidade;
    float subtotal;
} ItemCarrinho;

// Registro final do pedido após o checkout (A venda concretizada)
typedef struct {
    int id_pedido;
    int id_usuario;
    float total;
    char status[20];
} Pedido;

#endif
