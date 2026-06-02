// ============================================================
// ARQUIVO: posvenda.c
// MÓDULO: Pós-Venda
// DESCRIÇÃO: Implementa o acompanhamento de pedidos e o sistema
//            de avaliação por nota (1-5) e comentário. Só permite
//            avaliar pedidos com status "Entregue".
// AUTORES: Grupo GlowUP
// ============================================================

#include <stdio.h>
#include <string.h>
#include "posvenda.h" 
#include "variaveis_globais.h" 

// Função: Gerencia o fluxo do menu de pós-venda
void menu_pos_venda(int indice_cliente) {
    int opcao;
    do {
        printf("\n--- PEDIDOS REALIZADOS ---\n");
        printf("1. Acompanhar Entrega\n");
        printf("2. Avaliar Produto\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado
        
        switch (opcao) {
        case 1:
            visualizarStatusPedido(indice_cliente); 
            break;
        case 2:
            avaliar_produto(indice_cliente);
            break;
        case 0:
            printf("Voltando para o menu principal.\n");
            break; 
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Função: Exibe o status de entrega garantindo a visualização apenas dos pedidos do próprio cliente
void visualizarStatusPedido(int indice_cliente) {
    printf("\n--- LISTA DE SEUS PEDIDOS ---\n");
    int pedidos_do_usuario = 0;
    
    // PROTEÇÃO DE DADOS: Lista apenas os pedidos associados ao ID do cliente logado
    for (int i = 0; i < total_pedidos; i++) {
        if (pedidos[i].id_usuario == usuarios[indice_cliente].id) {
            printf(" -> Pedido ID: %d | Status: %s\n", pedidos[i].id_pedido, pedidos[i].status);
            pedidos_do_usuario++;
        }
    }
    
    // Caso o cliente ainda não tenha feito nenhuma compra
    if (pedidos_do_usuario == 0) {
        printf("Nenhum pedido registrado na sua conta.\n");
        printf("-----------------------------------\n");
        return;
    }
    printf("-----------------------------------\n");

    int id_pedido;
    printf("Digite o ID do pedido para acompanhar a entrega: ");
    scanf(" %d", &id_pedido);
    getchar(); 

    int encontrado = 0;
    
    // Busca o pedido específico solicitado pelo usuário
    for (int i = 0; i < total_pedidos; i++) {
        // TRAVA DE SEGURANÇA DUPLA: Confirma se o pedido existe E se pertence ao usuário atual
        if (pedidos[i].id_pedido == id_pedido && pedidos[i].id_usuario == usuarios[indice_cliente].id) {
            printf("\n>> Acompanhando a entrega do pedido ID: %d...\n", id_pedido);
            printf(">> Status Atual: %s\n", pedidos[i].status); 
            encontrado = 1;
            break; // Otimização: interrompe o laço após encontrar
        }
    }

    if (!encontrado) {
        printf("Pedido nao encontrado ou nao pertence a sua conta.\n"); 
    }
}

// Função: Permite dar nota e comentar sobre um pedido que já foi "Entregue"
void avaliar_produto(int indice_cliente) {
    printf("\n--- LISTA DE SEUS PEDIDOS ---\n");
    int pedidos_do_usuario = 0;
    
    // Lista os pedidos do usuário para facilitar a escolha
    for (int i = 0; i < total_pedidos; i++) {
        if (pedidos[i].id_usuario == usuarios[indice_cliente].id) {
            printf(" -> Pedido ID: %d | Status: %s\n", pedidos[i].id_pedido, pedidos[i].status);
            pedidos_do_usuario++;
        }
    }
    
    if (pedidos_do_usuario == 0) {
        printf("Nenhum pedido entregue para avaliar.\n");
        printf("-----------------------------------\n");
        return;
    }
    printf("-----------------------------------\n");

    Avaliacao avaliacao;
    printf("Digite o ID do pedido para avaliar o produto: ");
    scanf(" %d", &avaliacao.id_pedido);
    getchar(); 

    int encontrado = 0;
    
    for (int i = 0; i < total_pedidos; i++) {
        // TRAVA DE SEGURANÇA: Impede que o usuário avalie a compra de terceiros
        if (pedidos[i].id_pedido == avaliacao.id_pedido && pedidos[i].id_usuario == usuarios[indice_cliente].id) {
            encontrado = 1;

            // REGRA DE NEGÓCIO: Só permite avaliação se o produto já chegou ao destino
            if (strcmp(pedidos[i].status, "Entregue") == 0) {
                
                printf("Digite a nota (1-5): ");
                scanf("%d", &avaliacao.nota);
                getchar(); 

                printf("Digite um comentario sobre o produto: ");
                // Usa fgets para permitir frases com espaços no comentário
                fgets(avaliacao.comentario, sizeof(avaliacao.comentario), stdin);
                // Remove a quebra de linha indesejada que o fgets insere no final
                avaliacao.comentario[strcspn(avaliacao.comentario, "\n")] = '\0'; 

                printf("\n>> Avaliacao registrada com sucesso para o pedido ID: %d. Agradecemos pelo feedback!\n", avaliacao.id_pedido);
                printf(">> Nota: %d\n", avaliacao.nota);
                printf(">> Comentario: %s\n", avaliacao.comentario);
            } else {
                // Bloqueia caso o pedido ainda esteja "Em Trânsito", "Processando", etc.
                printf("Avaliacao bloqueada. O status do pedido e: %s\n", pedidos[i].status);
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Pedido nao encontrado ou nao pertence a sua conta.\n");
    }
}