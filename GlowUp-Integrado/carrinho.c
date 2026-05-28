// ============================================================
// ARQUIVO: carrinho.c
// MÓDULO: Carrinho de Compras
// DESCRIÇÃO: Gerencia os itens que o cliente escolheu antes de
//            pagar. Valida estoque ao adicionar e calcula o total.
//            Os dados ficam em memória até o checkout ser concluído.
// AUTORES: Grupo GlowUP
// ============================================================

#include <stdio.h>
#include <string.h>
#include "carrinho.h"
#include "variaveis_globais.h"

// Função: Mostra o que tem no carrinho com um design bem bonito
void exibirCarrinho() {
    printf("\n=========================================\n");
    printf("|             SEU CARRINHO              |\n");
    printf("=========================================\n");
    
    if (qtd_itens_carrinho == 0) {
        printf("| O carrinho esta vazio!                |\n");
        printf("=========================================\n");
        return;
    }
    
    float total = 0;
    // Varre o carrinho e cruza com o catálogo para pegar o nome do produto
    for(int i = 0; i < qtd_itens_carrinho; i++) {
        char nome_produto[100] = "";
        
        for(int j = 0; j < total_produtos; j++) {
            if(catalogo[j].id == carrinho[i].id_produto) {
                strcpy(nome_produto, catalogo[j].nome);
                break;
            }
        }
        
        printf(" %d. %s (Qtd: %d) - R$ %.2f\n", i+1, nome_produto, carrinho[i].quantidade, carrinho[i].subtotal);
        total += carrinho[i].subtotal;
    }
    printf("-----------------------------------------\n");
    printf(" SUBTOTAL: R$ %.2f\n", total);
    printf("=========================================\n");
}

// Função: Valida estoque e insere o item no vetor do carrinho
void adicionarProdutoCarrinho(int id, int qtd) {
    for (int i = 0; i < total_produtos; i++) {
        if (catalogo[i].id == id) { 
            if (catalogo[i].estoque >= qtd) { 
                carrinho[qtd_itens_carrinho].id_produto = id;
                carrinho[qtd_itens_carrinho].quantidade = qtd;
                carrinho[qtd_itens_carrinho].subtotal = qtd * catalogo[i].preco;
                
                qtd_itens_carrinho++; 
                printf(">> Sucesso: Produto adicionado ao carrinho!\n");
            } else {
                printf(">> Erro: Estoque insuficiente.\n");
            }
            return; 
        }
    }
    printf(">> Erro: Produto nao encontrado no catalogo.\n");
}

// Função Auxiliar: Isola a matemática do subtotal
float calcularSubtotalCarrinho() {
    float subtotal = 0.0;
    for(int i = 0; i < qtd_itens_carrinho; i++) {
        subtotal += carrinho[i].subtotal; 
    }
    return subtotal;
}