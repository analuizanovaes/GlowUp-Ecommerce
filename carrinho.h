// ============================================================
// ARQUIVO: carrinho.h
// DESCRIÇÃO: Índice das funções que controlam a "cestinha" do cliente. 
//            Adicionar itens, somar os preços e mostrar a lista.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef CARRINHO_H
#define CARRINHO_H       

#include "estruturas.h"      
#include "variaveis_globais.h" 

// --- Funções que controlam os itens do carrinho ---

void exibirCarrinho();
void adicionarProdutoCarrinho(int id, int qtd);
float calcularSubtotalCarrinho();

#endif