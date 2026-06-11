// ============================================================================
// ARQUIVO: checkout.c
// DESCRIÇÃO: Aqui fica o código de finalização da compra. É a parte que calcula
//            o frete, pergunta se tem cupom, imita a tela do cartão/Pix e, se
//            tudo der certo, salva a compra de vez.
// ============================================================================

#include <stdio.h>
#include <string.h>
#include "checkout.h"
#include "variaveis_globais.h"

// Se a compra for de 150 reais para cima, o frete é grátis. Senão, custa R$ 19,90.
float calcularFrete(float subtotal_carrinho)
{
    return (subtotal_carrinho >= 150.00) ? 0.00 : 19.90;
}

// Pergunta se o cliente tem cupom de desconto. Se ele digitar "GLOW10", ganha 10%.
float aplicarCupom(float subtotal_carrinho)
{
    char quer_cupom, cupom_digitado[20];
    printf("\nPossui cupom? (S/N): ");
    scanf(" %c", &quer_cupom);

    if (quer_cupom == 'S' || quer_cupom == 's')
    {
        printf("Codigo: ");
        scanf("%19s", cupom_digitado);

        // Verifica se a palavra digitada foi o nosso código secreto
        if (strcmp(cupom_digitado, "GLOW10") == 0)
            return subtotal_carrinho * 0.10; // Tira 10% do valor
    }
    return 0.00;
}

// Mostra o extrato e pede para o cliente escolher como quer pagar
int processarPagamento(float total_pagar)
{
    int opcao;
    char confirmar;

    printf("\n");
    printf("+===================================================+\n");
    printf("|                    PAGAMENTO                      |\n");
    printf("+===================================================+\n");

    printf("| Valor Total: R$ %-33.2f |\n", total_pagar);

    printf("+===================================================+\n");
    printf("| 1. PIX                                            |\n");
    printf("| 2. Boleto                                         |\n");
    printf("| 3. Cartao                                         |\n");
    printf("+===================================================+\n");

    printf("Escolha uma opcao: ");

    // Proteção para o caso do cliente digitar uma letra aqui também
    if (scanf("%d", &opcao) != 1)
    {
        while (getchar() != '\n')
            ;
        return 0; // Dá erro e volta para trás
    }

    while (getchar() != '\n');

    switch (opcao)
    {
    case 1:
        printf("\n");
        printf("+===================================================+\n");
        printf("|                       PIX                         |\n");
        printf("+===================================================+\n");
        printf("| Chave PIX:                                        |\n");
        printf("| glowup@pagamentos.com                             |\n");
        printf("+===================================================+\n");
        break;

    case 2:
        printf("\n");
        printf("+===================================================+\n");
        printf("|                     BOLETO                        |\n");
        printf("+===================================================+\n");
        printf("| Boleto gerado com sucesso!                        |\n");
        printf("+===================================================+\n");
        break;

    case 3:
        printf("\n");
        printf("+===================================================+\n");
        printf("|                     CARTAO                        |\n");
        printf("+===================================================+\n");
        printf("| Pagamento aprovado!                               |\n");
        printf("+===================================================+\n");
        break;

    default:
        printf("\n>> Opcao invalida.\n");
        return 0;
    }

    // Última pergunta antes de salvar a compra de vez
    printf("\nConfirmar pagamento? (S/N): ");
    scanf(" %c", &confirmar);

    while (getchar() != '\n');

    if (confirmar == 'S' || confirmar == 's')
    {
        printf("\n>> Pagamento realizado com sucesso!\n");
        return 1; // Avisa o main.c que deu tudo certo e pode faturar
    }

    printf("\n>> Pagamento cancelado.\n");
    return 0;
}

// Pega os itens do carrinho, tira do estoque da loja e salva na lista de pedidos
void faturarPedido(float total_final, int indice_cliente)
{
    if (total_pedidos >= 100)
    {
        printf("\n>> Erro Critico: Limite maximo de pedidos do sistema atingido.\n");
        return;
    }

    // Procura cada item que estava no carrinho lá no nosso catálogo para diminuir o estoque
    for (int i = 0; i < qtd_itens_carrinho; i++)
    {
        for (int j = 0; j < total_produtos; j++)
        {
            if (carrinho[i].id_produto == catalogo[j].id)
                catalogo[j].estoque -= carrinho[i].quantidade;
        }
    }

    // Cria a "nota fiscal" do pedido e salva na nossa lista final
    pedidos[total_pedidos].id_pedido = 100 + total_pedidos;
    pedidos[total_pedidos].id_usuario = usuarios[indice_cliente].id;
    pedidos[total_pedidos].total = total_final;
    strcpy(pedidos[total_pedidos].status, "Pagamento Confirmado");

    // Inicializa os dados de avaliação para evitar lixo de memória
    pedidos[total_pedidos].avaliado = 0;           // 0 significa Falso (o cliente ainda não avaliou este pedido)
    pedidos[total_pedidos].nota = 0;               // Zera a nota, já que a avaliação de 1 a 5 ainda não aconteceu
    strcpy(pedidos[total_pedidos].comentario, ""); // Deixa o texto do comentário completamente vazio

    printf("\n>> Pedido %d confirmado!\n", pedidos[total_pedidos].id_pedido);

    total_pedidos++;        // Aumenta a conta de quantos pedidos a loja já teve
    qtd_itens_carrinho = 0; // Zera o carrinho para o cliente poder fazer outras compras
}