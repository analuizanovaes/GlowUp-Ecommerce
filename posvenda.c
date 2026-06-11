// ============================================================================
// ARQUIVO: posvenda.c
// DESCRIÇÃO: Aqui fica o código da área de pós-venda. É onde o cliente 
//            consegue ver onde está o pedido dele e deixar um comentário 
//            se gostou ou não da compra.
// ============================================================================

#include <stdio.h>
#include <string.h>
#include "posvenda.h"
#include "variaveis_globais.h"

// Mostra o menu de opções na tela e espera o cliente digitar um número
void menu_pos_venda() {
    int opcao;
    do {
        printf("\n=========================================\n");
        printf("|           MENU POS-VENDA              |\n");
        printf("=========================================\n");
        printf("| 1. Acompanhar Entrega (Detalhes)      |\n");
        printf("| 2. Avaliar Produto                    |\n");
        printf("| 0. Voltar ao Menu Principal           |\n");
        printf("=========================================\n");
        printf("Opcao: ");
        
        // Se a pessoa digitar uma letra em vez de número, isso evita que o sistema trave
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            continue;
        }
        
        // Limpa o que sobrou no teclado para a próxima pergunta
        while (getchar() != '\n');

        // Chama a função certa dependendo da escolha
        switch (opcao) {
            case 1: visualizarStatusPedido(); break;
            case 2: avaliarProduto(); break;
            case 0: printf(">> Voltando ao painel principal...\n"); break;
            default: printf(">> Opcao invalida!\n");
        }
    } while (opcao != 0); // Fica rodando até o cliente digitar 0 para voltar
}

// Permite que o cliente dê uma nota (de 1 a 5) e escreva um comentário sobre a compra.
// Só funciona se a caixa já tiver chegado ("Entregue") e se ainda não foi avaliada.
void avaliarProduto() { 
    int id;
    printf("\nID do Pedido: ");
    if (scanf("%d", &id) != 1) { while (getchar() != '\n'); return; }

    // Procura o pedido na nossa lista pelo número que o cliente digitou
    for (int i = 0; i < total_pedidos; i++) {
        if (pedidos[i].id_pedido == id) {
            
            // Regra: Só pode avaliar se já estiver sido entregue
            if (strcmp(pedidos[i].status, "Entregue") == 0) {
                
                // Regra: Não pode avaliar a mesma compra duas vezes
                if (pedidos[i].avaliado) {
                    printf(">> Este pedido ja foi avaliado.\n");
                    return;
                }
                
                printf("Nota (1-5): ");
                scanf("%d", &pedidos[i].nota);
                while(getchar() != '\n'); 
                
                printf("Comentario: ");
                scanf(" %99[^\n]", pedidos[i].comentario);
                while(getchar() != '\n'); 
                
                pedidos[i].avaliado = 1; // Salva que o cliente já avaliou
                printf(">> Avaliacao registrada!\n");
            } else {
                printf(">> Status atual (%s) nao permite avaliacao.\n", pedidos[i].status);
            }
            return;
        }
    }
    printf(">> Pedido nao localizado.\n"); // Mensagem se o ID não existir
}

// Procura o pedido pelo ID e mostra se já foi entregue ou não. 
// E se o cliente já deu uma nota, mostra a nota e o comentário dele também.
void visualizarStatusPedido() {
    int id;
    printf("\nID do Pedido: ");
    if (scanf("%d", &id) != 1) { while (getchar() != '\n'); return; }

    for (int i = 0; i < total_pedidos; i++) {
        if (pedidos[i].id_pedido == id) {
            printf("\n--- Detalhes do Pedido %d ---\n", pedidos[i].id_pedido);
            printf("Status: %s\n", pedidos[i].status);
            
            // Se já foi avaliado, exibe a nota na tela
            if (pedidos[i].avaliado == 1) {
                printf("Nota registrada: %d/5\n", pedidos[i].nota);
                printf("Seu comentario: %s\n", pedidos[i].comentario);
            } else {
                printf("Este pedido ainda nao foi avaliado.\n");
            }
            return;
        }
    }
    printf(">> Pedido nao localizado.\n");
}