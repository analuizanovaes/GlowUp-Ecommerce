// ============================================================================
// ARQUIVO: checkout.h
// DESCRIÇÃO: Índice das funções que cuidam da hora de fechar a compra, calcular 
//            o frete e simular o pagamento.
// ============================================================================

#ifndef CHECKOUT_H
#define CHECKOUT_H

float calcularFrete(float subtotal_carrinho);
float aplicarCupom(float subtotal_carrinho);
int processarPagamento(float total_pagar);
void faturarPedido(float total_final, int indice_cliente);

#endif