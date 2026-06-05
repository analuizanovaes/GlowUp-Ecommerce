#include <stdio.h>
#include <string.h>
#include "estruturas.h" 
#include "catalogo.h"   

// O 'extern' conecta este arquivo à memória global declarada na main
extern Produto catalogo[];

// Mostra apenas produtos com estoque positivo (Regra de Negócio)
void listarProdutos(int total_produtos) {
    printf("\n--- PRODUTOS EM ESTOQUE ---\n");
    
    for (int i = 0; i < total_produtos; i++) {
        if (catalogo[i].estoque > 0) {
            printf("ID: %d | Nome: %s | Categoria: %s | Preco: R$ %.2f | Qtd Estoque: %d\n",
                   catalogo[i].id,
                   catalogo[i].nome,
                   catalogo[i].categoria,
                   catalogo[i].preco,
                   catalogo[i].estoque);
        }
    }
    printf("---------------------------\n");
}

// Busca produtos no catálogo por correspondência de nome
void buscarProdutoPorNome(int total_produtos) {
    char termo_busca[100];
    int encontrado = 0; 

    printf("\nDigite uma palavra para buscar no catalogo: ");
    scanf(" %[^\n]", termo_busca); 
    
    // Limpeza do buffer do teclado para evitar saltos em leituras seguintes
    while (getchar() != '\n');

    printf("\n--- RESULTADOS DA BUSCA ---\n");
    
    for (int i = 0; i < total_produtos; i++) {
        if (strstr(catalogo[i].nome, termo_busca) != NULL) {
            printf("ID: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                   catalogo[i].id, 
                   catalogo[i].nome, 
                   catalogo[i].preco, 
                   catalogo[i].estoque);
            encontrado = 1; 
        }
    }

    if (encontrado == 0) {
        printf("Nenhum produto encontrado.\n");
    }
    printf("---------------------------\n");
}
