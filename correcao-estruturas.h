#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// =======================================================================
// Aqui criamos os moldes dos dados. Não tem lógica de programação aqui, 
// apenas a estrutura do que é um Usuário, um Produto, etc.
// =======================================================================

// Definição do perfil de usuário (Quem compra)
typedef struct {
    int id;
    char nome[100];
    char cpf[15];
    char email[100];
    char senha[50];
    
    // --- CORREÇÃO LOGÍSTICA (CT-09 e CT-22) ---
    // Dividir o endereço em campos específicos isola os dados.
    // Evita falsos-positivos com "brasilia" em outras partes do texto.
    char logradouro[100]; // Armazena o nome da Rua/Avenida
    char numero[10];      // Armazena o número da residência (ajuda na validação da vírgula)
    char cidade[50];      // Armazena estritamente a Cidade (Filtragem limpa para o CT-22)
    char uf[3];           // Armazena a Unidade Federativa (Ex: DF, SP, RJ)
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
