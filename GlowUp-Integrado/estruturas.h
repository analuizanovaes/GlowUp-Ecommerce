// ============================================================
// ARQUIVO: estruturas.h
// MÓDULO: Moldes de Dados (Structs)
// ============================================================

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// ==========================================
// MOLDES DE DADOS (STRUCTS)
// As structs funcionam como "fichas" que agrupam varias informacoes.
// ==========================================

// Ficha do cliente
typedef struct {
    int id;               
    char nome[100];       
    int idade;            
    char cpf[15];         
    char email[100];      
    char senha[50];       
    char endereco[200];   
    char telefone[20];    
    int bloqueado;        
} Usuario;

// Ficha do produto
typedef struct {
    int id;               
    char nome[100];       
    char categoria[50];   
    float preco;          
    int estoque;          
} Produto;

// Ficha do item no carrinho
typedef struct {
    int id_produto;       
    int quantidade;       
    float subtotal;       
} ItemCarrinho;

// Ficha do pedido final
typedef struct {
    int id_pedido;        
    int id_usuario;       
    float total;          
    char status[20];      
} Pedido;

// Ficha de avaliacao
typedef struct {
    int id_pedido;        
    int nota;             
    char comentario[100]; 
} Avaliacao; 

#endif