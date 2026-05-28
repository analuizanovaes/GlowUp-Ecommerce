// ============================================================
// ARQUIVO: variaveis_globais.h
// MÓDULO: Memória Compartilhada do Sistema
// DESCRIÇÃO: Declara (com 'extern') todos os vetores e contadores
//            que são DEFINIDOS fisicamente em main.c.
//
//            CONCEITO IMPORTANTE — extern:
//            A palavra 'extern' não cria a variável; ela avisa ao
//            compilador "essa variável existe em outro arquivo, confie
//            em mim". A criação real acontece em main.c (sem extern).
//            Todos os módulos (.c) incluem este header para acessar
//            a memória central sem precisar criar cópias.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef VARIAVEIS_GLOBAIS_H   // Guarda de inclusão
#define VARIAVEIS_GLOBAIS_H

#include "estruturas.h"       // Precisamos dos tipos Usuario, Produto, etc.

// Limite máximo de clientes cadastrados no sistema
#define MAX 100

// ------------------------------------------------------------
// MÓDULO USUÁRIOS (usuarios.c / main.c)
// ------------------------------------------------------------
extern Usuario usuarios[MAX];  // Vetor com todos os clientes cadastrados
extern int totalUsuarios;      // Contador: quantos clientes existem hoje

// ------------------------------------------------------------
// MÓDULO CATÁLOGO (catalogo.c / main.c)
// ------------------------------------------------------------
extern Produto catalogo[50];   // Vetor com todos os produtos da loja
extern int total_produtos;     // Contador: quantos produtos existem

// ------------------------------------------------------------
// MÓDULO CARRINHO (carrinho.c / main.c)
// ------------------------------------------------------------
extern ItemCarrinho carrinho[50];  // Vetor com os itens da compra atual
extern int qtd_itens_carrinho;     // Contador: quantos itens no carrinho agora

// ------------------------------------------------------------
// MÓDULO PEDIDOS (checkout.c / main.c)
// ------------------------------------------------------------
extern Pedido pedidos[100];    // Histórico de todos os pedidos finalizados
extern int total_pedidos;      // Contador: quantos pedidos já foram feitos

#endif // fim do VARIAVEIS_GLOBAIS_H
