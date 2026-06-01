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

void menu_pos_venda()
{
    int opcao;
    do
    {
        printf("\n--- PEDIDOS REALIZADOS ---\n");
        printf("1. Acompanhar Entrega\n");
        printf("2. Avaliar Produto\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            visualizarStatusPedido();
            break;
        case 2:
            avaliar_produto();
            break;
        case 0:
            printf("Voltando para o menu principal.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void visualizarStatusPedido()
{
    // --- NOVIDADE: Mostra os IDs válidos para o usuário não se perder ---
    printf("\n--- LISTA DE PEDIDOS NO SISTEMA ---\n");
    if (total_pedidos == 0)
    {
        printf("Nenhum pedido registrado ainda.\n");
        return;
    }
    for (int i = 0; i < total_pedidos; i++)
    {
        printf(" -> Pedido ID: %d | Status: %s\n", pedidos[i].id_pedido, pedidos[i].status);
    }
    printf("-----------------------------------\n");

    int id_pedido;
    printf("Digite o ID do pedido para acompanhar a entrega: ");
    scanf(" %d", &id_pedido);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < total_pedidos; i++)
    {
        if (pedidos[i].id_pedido == id_pedido)
        {
            printf("\n>> Acompanhando a entrega do pedido ID: %d...\n", id_pedido);
            printf(">> Status Atual: %s\n", pedidos[i].status);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Pedido nao encontrado no sistema.\n");
    }
}

void avaliar_produto()
{
    // --- NOVIDADE: Mostra os IDs válidos ---
    printf("\n--- LISTA DE PEDIDOS NO SISTEMA ---\n");
    if (total_pedidos == 0)
    {
        printf("Nenhum pedido registrado ainda para avaliar.\n");
        return;
    }
    for (int i = 0; i < total_pedidos; i++)
    {
        printf(" -> Pedido ID: %d | Status: %s\n", pedidos[i].id_pedido, pedidos[i].status);
    }
    printf("-----------------------------------\n");

    Avaliacao avaliacao;
    printf("Digite o ID do pedido para avaliar o produto: ");
    scanf(" %d", &avaliacao.id_pedido);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < total_pedidos; i++)
    {
        if (pedidos[i].id_pedido == avaliacao.id_pedido)
        {
            encontrado = 1;

            if (strcmp(pedidos[i].status, "Entregue") == 0)
            {
                printf("Digite a nota (1-5): ");
                if (scanf("%d", &avaliacao.nota) != 1)
                {
                    printf("\n>> Erro: Entrada invalida. Digite apenas numeros.\n");
                    while (getchar() != '\n');
                    return;
                }
                while (getchar() != '\n');

                printf("Digite um comentario sobre o produto: ");
                fgets(avaliacao.comentario, sizeof(avaliacao.comentario), stdin);
                avaliacao.comentario[strcspn(avaliacao.comentario, "\n")] = '\0';

                printf("\n>> Avaliacao registrada com sucesso para o pedido ID: %d. Agradecemos pelo feedback!\n", avaliacao.id_pedido);
                printf(">> Nota: %d\n", avaliacao.nota);
                printf(">> Comentario: %s\n", avaliacao.comentario);
            }
            else
            {
                printf("Avaliacao bloqueada. O status do pedido e: %s\n", pedidos[i].status);
            }
            break;
        }
    }

    if (!encontrado)
    {
        printf("Pedido nao encontrado no sistema.\n");
    }
}
