#include <stdio.h>
#include <string.h>
#include "estruturas.h" // Precisa conhecer o molde do "Produto"  
#include "catalogo.h"   // Boa prática: inclui o próprio cabeçalho para validar as assinaturas

// =======================================================================
// Implementar a lógica de exibição e busca de produtos.
// Aqui é onde a mágica do catálogo acontece. Usamos o extern para acessar o vetor de produtos que foi instanciado lá na main.
// =======================================================================

// O 'extern' conecta este arquivo à memória global declarada na main
extern Produto catalogo[];

// -----------------------------------------------------------------------
// FUNÇÃO: listarProdutos
// DESTAQUE: Mostra apenas produtos com estoque positivo (Regra de Negócio)
// -----------------------------------------------------------------------
void listarProdutos(int total_produtos) {
    printf("\n--- PRODUTOS EM ESTOQUE ---\n");
    
    for (int i = 0; i < total_produtos; i++) {
        // Esta é a validação de estoque exigida nos requisitos. 
        // Se o estoque for 0, o laço ignora o item e não exibe na tela.
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

// -----------------------------------------------------------------------
// FUNÇÃO: buscarProdutoPorNome
// DESTAQUE: Uso do strstr para encontrar partes de palavras
// -----------------------------------------------------------------------
void buscarProdutoPorNome(int total_produtos) {
    char termo_busca[100];
    int encontrado = 0; // Flag: 0 = Não achou nada | 1 = Achou pelo menos um

    printf("\nDigite uma palavra para buscar no catalogo: ");
    
    // Usamos o formatador %[^\n] no scanf para permitir que o cliente digite nomes compostos com espaços (ex: Serum Vitamina).
    scanf(" %[^\n]", termo_busca); 
    
    // Limpeza do buffer do teclado para evitar que o próximo input do sistema seja pulado
    while (getchar() != '\n');

    printf("\n--- RESULTADOS DA BUSCA ---\n");
    
    for (int i = 0; i < total_produtos; i++) {
        // A função strstr da biblioteca string.h foi usada porque ela procura o 'termo_busca' dentro do nome inteiro do produto. 
        // Se achar alguma correspondência, ela retorna diferente de NULL.
        if (strstr(catalogo[i].nome, termo_busca) != NULL) {
            printf("ID: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                   catalogo[i].id, 
                   catalogo[i].nome, 
                   catalogo[i].preco, 
                   catalogo[i].estoque);
            encontrado = 1; // Sinaliza sucesso na busca
        }
    }

    // Se o laço terminar e a flag continuar 0, acionamos o tratamento de erro conforme definido na HU04.
    if (encontrado == 0) {
        printf("Nenhum produto encontrado.\n");
    }
    printf("---------------------------\n");
}
