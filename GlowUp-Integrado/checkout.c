// ============================================================
// ARQUIVO: checkout.c
// MÓDULO: Checkout e Faturamento
// DESCRIÇÃO: Implementa todo o fluxo de compra após o carrinho:
//            validação de endereço, frete, cupons, gateway de
//            pagamento e geração do pedido com baixa no estoque.
// AUTORES: Grupo GlowUP
// ============================================================

#include <stdio.h>
#include <string.h>
#include "checkout.h"
#include "variaveis_globais.h"

// Regra de Negócio: Bloqueia entregas internacionais
int validarEndereco(char endereco_digitado[]) {
    if (strstr(endereco_digitado, "Brasil") != NULL || strstr(endereco_digitado, "brasil") != NULL) {
        return 1; 
    } else {
        printf("\n>> Regra de Negocio: Endereco invalido. Entregas apenas no Brasil.\n");
        return 0; 
    }
}

// Lógica de cálculo de logística
float calcularFrete(float subtotal_carrinho) {
    float frete = 19.90;
    printf("\n>> Simulando conexao com transportadora...\n");
    if (subtotal_carrinho >= 150.00) {
        frete = 0.00;
        printf(">> Parabens! O subtotal atingiu R$ %.2f e voce ganhou FRETE GRATIS!\n", subtotal_carrinho);
    } else {
        printf(">> O valor do frete fixo nacional e: R$ %.2f\n", frete);
    }
    return frete;
}

// Lógica de marketing para cupons
float aplicarCupom(float subtotal_carrinho) {
    char quer_cupom;
    char cupom_digitado[20];
    float valor_desconto = 0.00;

    printf("\nVoce tem um cupom de desconto? (S/N): ");
    scanf(" %c", &quer_cupom); 

    if (quer_cupom == 'S' || quer_cupom == 's') {
        printf("Digite o codigo do cupom (Tente: GLOW10): ");
        scanf("%s", cupom_digitado);

        if (strcmp(cupom_digitado, "GLOW10") == 0) {
            valor_desconto = subtotal_carrinho * 0.10; 
            printf(">> Sucesso! Desconto de 10%% aplicado.\n");
        } else {
            printf(">> Cupom invalido ou expirado.\n");
        }
    }
    return valor_desconto;
}

// =====================
// GATEWAY DE PAGAMENTO 
// =====================
int processarPagamento(float total_pagar) {
    int opcao;
    printf("\n=========================================\n");
    printf("|          GATEWAY DE PAGAMENTO         |\n");
    printf("=========================================\n");
    printf(" Total a pagar: R$ %.2f\n", total_pagar);
    printf("-----------------------------------------\n");
    printf(" 1. PIX (Aprovacao instantanea)\n");
    printf(" 2. Boleto Bancario (Ate 3 dias uteis)\n");
    printf(" 3. Cartao de Credito/Debito\n");
    printf("=========================================\n");
    printf(" Escolha a forma de pagamento: ");
    
    scanf("%d", &opcao);
    
    if(opcao >= 1 && opcao <= 3) {
        printf("\n>> Aguardando operadora... Pagamento Aprovado!\n");
        return 1; 
    }
    
    printf("\n>> Opcao invalida! Pagamento Cancelado.\n");
    return 0; 
}

// Função Crítica: Dá baixa no estoque e registra a venda oficial
void faturarPedido(float total_final, int indice_cliente) {
    
    for (int i = 0; i < qtd_itens_carrinho; i++) {
        for (int j = 0; j < total_produtos; j++) {
            if (carrinho[i].id_produto == catalogo[j].id) {
                catalogo[j].estoque -= carrinho[i].quantidade;
            }
        }
    }
    
    // O pedido começa no 100! (Ex: 100, 101, 102)
    pedidos[total_pedidos].id_pedido = 100 + total_pedidos;
    pedidos[total_pedidos].id_usuario = usuarios[indice_cliente].id;
    pedidos[total_pedidos].total = total_final;
    strcpy(pedidos[total_pedidos].status, "Entregue"); 
    
    printf("\n===================================================\n");
    printf("              FATURA GERADA COM SUCESSO            \n");
    printf("===================================================\n");
    printf("  >>> SEU NUMERO DE PEDIDO E: %d <<< \n", pedidos[total_pedidos].id_pedido);
    printf("  Status do envio: %s\n", pedidos[total_pedidos].status);
    printf("===================================================\n");
    printf(">> E-mail de confirmacao enviado!\n");
    
    total_pedidos++; 
    qtd_itens_carrinho = 0; 
}