#include <stdio.h>
#include <string.h> 
#include "catalogo.h"
#include "variaveis_globais.h"

void listarProdutos() {
    printf("\n=================================================================\n");
    printf("|                      CATALOGO DE PRODUTOS                     |\n");
    printf("=================================================================\n");
    
    int itens_exibidos = 0;

    for (int i = 0; i < total_produtos; i++) {
        if (catalogo[i].estoque > 0) {
            printf("| ID: %-2d | %-30s | R$ %-6.2f | Estq: %-2d |\n", 
                   catalogo[i].id, 
                   catalogo[i].nome, 
                   catalogo[i].preco, 
                   catalogo[i].estoque);
            itens_exibidos++;
        }
    }
    
    if (itens_exibidos == 0) {
        printf("| Nenhum produto disponivel em estoque no momento.              |\n");
    }
    printf("=================================================================\n");
}

void buscarProdutoPorNome() {
    char termo_busca[100];
    int encontrado = 0;

    printf("\nDigite uma palavra para buscar no catalogo: ");
    scanf(" %99[^\n]", termo_busca);

    printf("\n=================================================================\n");
    printf("|                      RESULTADOS DA BUSCA                      |\n");
    printf("=================================================================\n");
    
    for (int i = 0; i < total_produtos; i++) {
        if (strstr(catalogo[i].nome, termo_busca) != NULL || strstr(catalogo[i].categoria, termo_busca) != NULL) {
            printf("| ID: %-2d | %-30s | R$ %-6.2f | Estq: %-2d |\n",
                   catalogo[i].id, 
                   catalogo[i].nome, 
                   catalogo[i].preco, 
                   catalogo[i].estoque);
            encontrado = 1; 
        }
    }

    if (encontrado == 0) {
        printf("| Nenhum produto encontrado correspondente a busca.             |\n");
    }
    printf("=================================================================\n");
}
