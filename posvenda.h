// ============================================================
// ARQUIVO: posvenda.h
// MÓDULO: Pós-Venda
// DESCRIÇÃO: Índice do módulo posvenda.c. Inclua para usar
//            o acompanhamento de entrega e avaliação de produtos.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef POSVENDA_H
#define POSVENDA_H

#include "estruturas.h"
#include "variaveis_globais.h"

// ------------------------------------------------------------
// ASSINATURAS DAS FUNÇÕES
// ------------------------------------------------------------

// Exibe o menu de opções do pós-venda para o usuário logado
void menu_pos_venda(int indice_cliente);

// Lista os pedidos exclusivos do cliente e permite verificar o status
void visualizarStatusPedido(int indice_cliente); 

// Permite ao cliente avaliar um pedido entregue (nota e comentário)
void avaliar_produto(int indice_cliente);

#endif