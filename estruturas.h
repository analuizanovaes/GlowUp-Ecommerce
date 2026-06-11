#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// =======================================================================
// MOLDES DE DADOS (STRUCTS)
// Aqui ficam as "fôrmas" que usamos para organizar e guardar as 
// informações no nosso sistema (como os dados do cliente e do produto).
// =======================================================================

// Molde com as informações que precisamos salvar de cada cliente
typedef struct {
    int id;               
    char nome[100];       
    int idade;            
    char cpf[15];         
    char email[100];      
    char senha[50];       
    char endereco[200];   
    char telefone[20];    
    int bloqueado; // Dica de segurança: 0 = Conta normal, 1 = Conta travada (errou muita senha)       
} Usuario;

// Molde com as informações de cada produto que vendemos na loja
typedef struct {
    int id;               
    char nome[100];       
    char categoria[50];   
    float preco;          
    int estoque;          
} Produto;

// Molde para os itens que o cliente coloca no carrinho antes de pagar
typedef struct {
    int id_produto;       
    int quantidade;       
    float subtotal; // É o valor daquele item vezes a quantidade escolhida
} ItemCarrinho;

// Molde para o histórico de um pedido que já foi pago e finalizado
typedef struct {
    int id_pedido;
    int id_usuario;
    float total;
    char status[20]; // Ex: "Entregue", "Pagamento Confirmado"
    int avaliado;    // Se for 0, ainda não avaliou. Se for 1, já deu nota.
    int nota;
    char comentario[100];
} Pedido;

// Molde para guardar a nota e o comentário que o cliente achou da compra
typedef struct {
    int id_pedido;        
    int nota;             
    char comentario[100]; 
} Avaliacao; 

#endif