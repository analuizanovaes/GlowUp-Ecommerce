// ============================================================================
// ARQUIVO: catalogo.c
// DESCRIÇÃO: Cuida da vitrine da loja. Lista todos os produtos que temos
//            para vender e ajuda o cliente a pesquisar pelo nome ou categoria.
// ============================================================================

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "catalogo.h"
#include "variaveis_globais.h"

// Pega nossa lista de produtos e imprime ela na tela (só exibe se o estoque for maior que zero)
void listarProdutos()
{
    printf("\n==================================================================\n");
    printf("|                      CATALOGO DE PRODUTOS                      |\n");
    printf("==================================================================\n");

    int itens_exibidos = 0;

    for (int i = 0; i < total_produtos; i++)
    {
        if (catalogo[i].estoque > 0)
        {
            printf("| ID: %-2d | %-30s | R$ %-6.2f | Estq: %-2d |\n",
                   catalogo[i].id,
                   catalogo[i].nome,
                   catalogo[i].preco,
                   catalogo[i].estoque);
            itens_exibidos++;
        }
    }

    if (itens_exibidos == 0)
    {
        printf("| Nenhum produto disponivel em estoque no momento.              |\n");
    }
    printf("==================================================================\n");
}

// Lê uma palavra que o cliente escreveu e procura no catálogo para ver se bate
void buscarProdutoPorNome()
{
    char termo_busca[100];
    int encontrado = 0;

    printf("\nDigite uma palavra para buscar no catalogo: ");
    scanf(" %99[^\n]", termo_busca);

    normalizarString(termo_busca); // Deixa tudo minúsculo para facilitar a busca

    printf("\n==================================================================\n");
    printf("|                      RESULTADOS DA BUSCA                       |\n");
    printf("==================================================================\n");

    for (int i = 0; i < total_produtos; i++)
    {
        char nome_temp[100], cat_temp[100];
        strcpy(nome_temp, catalogo[i].nome);
        strcpy(cat_temp, catalogo[i].categoria);

        // Deixa o nome e a categoria do produto minúsculos também para comparar direito
        normalizarString(nome_temp);
        normalizarString(cat_temp);

        // Se achar um pedaço da palavra dentro do nome ou da categoria, mostra na tela
        if (strstr(nome_temp, termo_busca) != NULL || strstr(cat_temp, termo_busca) != NULL)
        {
            printf("| ID: %-2d | %-30s | R$ %-6.2f | Estq: %-2d |\n",
                   catalogo[i].id,
                   catalogo[i].nome,
                   catalogo[i].preco,
                   catalogo[i].estoque);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("| Nenhum produto encontrado correspondente a busca.             |\n");
    }
    printf("==================================================================\n");
}

// Pega uma palavra qualquer e transforma todas as letras em minúsculas. 
// Isso ajuda muito: assim, procurar "Batom" ou "batom" vai achar a mesma coisa!
void normalizarString(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}