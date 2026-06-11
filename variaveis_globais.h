// ============================================================
// ARQUIVO: variaveis_globais.h
// DESCRIÇÃO: Este arquivo avisa para todas as outras partes do 
//            programa quais são as listas (vetores) de dados 
//            que existem. A palavra 'extern' significa:
//            "Ei, essa variável já foi criada de verdade lá no 
//            arquivo main.c, pode usar ela à vontade aqui também!".
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef VARIAVEIS_GLOBAIS_H   // Evita que o programa leia este arquivo duas vezes sem querer
#define VARIAVEIS_GLOBAIS_H

#include "estruturas.h"       // Precisamos dos moldes (Usuario, Produto, etc.) que criamos

// Número máximo de clientes que cabem no nosso sistema
#define MAX 100

// ------------------------------------------------------------
// DADOS DOS USUÁRIOS
// ------------------------------------------------------------
extern Usuario usuarios[MAX];  // Lista com todos os clientes cadastrados
extern int totalUsuarios;      // Conta quantos clientes já se cadastraram até agora

// ------------------------------------------------------------
// DADOS DOS PRODUTOS DA LOJA
// ------------------------------------------------------------
extern Produto catalogo[50];   // Lista com todos os produtos que vendemos
extern int total_produtos;     // Conta quantos produtos existem na loja hoje

// ------------------------------------------------------------
// DADOS DO CARRINHO DE COMPRAS
// ------------------------------------------------------------
extern ItemCarrinho carrinho[50];  // Lista dos itens que estão no carrinho neste exato momento
extern int qtd_itens_carrinho;     // Conta quantos itens o cliente já colocou no carrinho

// ------------------------------------------------------------
// DADOS DOS PEDIDOS FINALIZADOS
// ------------------------------------------------------------
extern Pedido pedidos[100];    // Histórico de todas as compras já pagas
extern int total_pedidos;      // Conta quantas compras já foram feitas no total

#endif // fim do arquivo