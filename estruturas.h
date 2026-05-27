#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Estrutura que representa o perfil de um cliente da loja
typedef struct {
    int id;               // Identificador unico do cliente
    char nome[100];       // Nome completo
    char cpf[15];         // Documento de identificacao
    char email[100];      // Email para login e contacto
    char senha[50];       // Senha de acesso ao sistema
    char endereco[200];   // Endereco completo para entrega
} Usuario;

// Estrutura que representa um item disponivel para venda
typedef struct {
    int id;               // Identificador unico do produto
    char nome[100];       // Nome comercial do produto
    char categoria[50];   // Categoria (Skincare, Maquiagem, etc)
    float preco;          // Valor unitario de venda
    int estoque;          // Quantidade fisica disponivel na prateleira
} Produto;

// Estrutura que guarda os itens que o cliente escolheu antes de pagar
typedef struct {
    int id_produto;       // Referencia ao ID do produto no catalogo
    int quantidade;       // Quantas unidades o cliente deseja
    float subtotal;       // Calculo de: preco do produto * quantidade
} ItemCarrinho;

// Estrutura que oficializa a compra apos o pagamento ser aprovado
typedef struct {
    int id_pedido;        // Numero oficial do pedido gerado (ex: Pedido 101)
    int id_usuario;       // ID do cliente que fez a compra
    float total;          // Valor final pago (subtotal + frete - desconto)
    char status[20];      // Estado do pedido (ex: Pendente, Aprovado)
} Pedido;

#endif
