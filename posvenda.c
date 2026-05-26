#include <stdio.h>
#include <string.h>
#include "posvenda.h" // Puxa posvenda.h e estruturas.h juntas

/**
 * Interface do menu de Pos-Venda.
 * Gerencia a navegação interna entre acompanhamento e avaliacao.
 */
void menu_pos_venda() {
    int opcao;
    do {
        printf("\n--- PEDIDOS REALIZADOS ---\n");
        printf("1. Acompanhar Entrega\n");
        printf("2. Avaliar Produto\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
        case 1:
            visualizarStatusPedido(); 
            break;
        case 2:
            avaliar_produto();
            break;
        case 0:
            printf("Voltando para o menu principal.\n");
            break; // Sai do loop
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

/**
 * Implementação da HU08: Acompanhar Entrega.
 * Verifica o status do pedido no vetor de pedidos.
 */
void visualizarStatusPedido() {
    int id_pedido;
    printf("\nDigite o ID do pedido para acompanhar a entrega: ");
    scanf(" %d", &id_pedido);
    getchar(); // Limpa o buffer de entrada

    int encontrado = 0;
    // Busca o pedido real no vetor de pedidos para mostrar o status
    for (int i = 0; i < total_pedidos; i++) {
        if (pedidos[i].id_pedido == id_pedido) {
            printf("Acompanhando a entrega do pedido ID: %d...\n", id_pedido);
            printf("Status: %s\n", pedidos[i].status); // Puxa o status real do vetor
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pedido não encontrado no sistema.\n");
    }
}

/**
 * Implementação da HU09: Avaliar Produto.
 * Permite que o cliente registre uma avaliação, mas APENAS se o status for "Entregue".
 */
void avaliar_produto()
{
    Avaliacao avaliacao;
    printf("\nDigite o ID do pedido para avaliar o produto: ");
    scanf(" %d", &avaliacao.id_pedido);
    getchar(); // Limpa o buffer de entrada

    int encontrado = 0;
    // Busca o pedido para checar se foi Entregue
    for (int i = 0; i < total_pedidos; i++)
    {
        if (pedidos[i].id_pedido == avaliacao.id_pedido)
        {
            encontrado = 1;

            // Permite avaliação apenas se o status do pedido for "Entregue"
            if (strcmp(pedidos[i].status, "Entregue") == 0)
            {

                printf("Digite a nota (1-5): ");
                scanf("%d", &avaliacao.nota);
                getchar(); // Limpa o buffer de entrada

                // Feedback do cliente
                printf("Digite um comentario sobre o produto: ");
                fgets(avaliacao.comentario, sizeof(avaliacao.comentario), stdin);
                avaliacao.comentario[strcspn(avaliacao.comentario, "\n")] = '\0'; // Remover nova linha

                // Simulação de armazenamento da avaliação
                printf("Avaliacao registrada com sucesso para o pedido ID: %d. Agradecemos pelo feedback!\n", avaliacao.id_pedido);
                printf("Nota: %d\n", avaliacao.nota);
                printf("Comentario: %s\n", avaliacao.comentario);
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