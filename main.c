#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "catalogo.h"  

// Vetores Globais reais (Memória do Sistema)
Usuario usuarios[100];
Produto catalogo[50];

// Função para popular o catálogo inicial (Mock de Dados)
void inicializarSistema() {
    catalogo[0].id = 1;
    strcpy(catalogo[0].nome, "Serum Vitamina C");
    strcpy(catalogo[0].categoria, "Skincare");
    catalogo[0].preco = 89.90;
    catalogo[0].estoque = 50;

    catalogo[1].id = 2;
    strcpy(catalogo[1].nome, "Base Matte Alta Cobertura");
    strcpy(catalogo[1].categoria, "Maquiagem");
    catalogo[1].preco = 55.00;
    catalogo[1].estoque = 30;

    printf("Sistema GlowUP inicializado com sucesso!\n");
}

int main() {
    inicializarSistema();
    
    printf("Item 1 carregado: %s (Estoque: %d)\n", catalogo[0].nome, catalogo[0].estoque);
    printf("Item 2 carregado: %s (Estoque: %d)\n", catalogo[1].nome, catalogo[1].estoque);
    
    listarProdutos(2);
    buscarProdutoPorNome(2);
    
    return 0;
}
