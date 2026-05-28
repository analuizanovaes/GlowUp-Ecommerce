// ============================================================
// ARQUIVO: carrinho.h
// MÓDULO: Carrinho de Compras
// DESCRIÇÃO: Assinaturas das funções que controlam os itens
//            que o cliente escolheu antes de finalizar o pedido.
//            Este arquivo é o "índice" do módulo carrinho.c.
//            Basta incluir este .h para usar as funções abaixo.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef CARRINHO_H       // Guarda de inclusão: evita que este header
#define CARRINHO_H       // seja processado duas vezes pelo compilador.

#include "estruturas.h"      // Precisamos da struct ItemCarrinho
#include "variaveis_globais.h" // Precisamos do vetor 'carrinho[]' e 'catalogo[]'

// ------------------------------------------------------------
// ASSINATURAS (PROTÓTIPOS) DAS FUNÇÕES DO MÓDULO
// O compilador lê estas linhas e sabe que as funções existem,
// mesmo que o corpo delas esteja em outro arquivo (.c).
// ------------------------------------------------------------

// Exibe na tela todos os itens que estão no carrinho atual,
// cruzando com o catálogo para mostrar o nome do produto.
void exibirCarrinho();

// Recebe o ID de um produto e a quantidade desejada,
// valida o estoque e insere o item no vetor do carrinho.
void adicionarProdutoCarrinho(int id, int qtd);

// Percorre o carrinho e soma todos os subtotais,
// retornando o valor total para o checkout usar.
float calcularSubtotalCarrinho();

#endif // fim do CARRINHO_H
