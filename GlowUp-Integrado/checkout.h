// ============================================================
// ARQUIVO: checkout.h
// MÓDULO: Checkout e Faturamento (HU06, HU07, HG02)
// DESCRIÇÃO: Índice do módulo checkout.c. Contém as funções de
//            validação de endereço, cálculo de frete, cupom,
//            pagamento e geração do pedido final.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef CHECKOUT_H
#define CHECKOUT_H

// ==========================================
// MÓDULO: CHECKOUT E FATURAMENTO (HU06, HU07, HG02)
// ==========================================
int validarEndereco(char endereco_digitado[]);
float calcularFrete(float subtotal_carrinho);
float aplicarCupom(float subtotal_carrinho);
int processarPagamento(float total_pagar);
void faturarPedido(float total_final, int indice_cliente);

#endif