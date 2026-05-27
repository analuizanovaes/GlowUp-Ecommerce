#ifndef DADOS_MARCELO_H
#define DADOS_MARCELO_H

#include <stdio.h>
#include <string.h>
#include "estruturas.h"

// ==========================================
// VETORES GLOBAIS E VARIAVEIS DE CONTROLE
// ==========================================
// Estes vetores funcionam como o banco de dados do nosso sistema estruturado
Usuario usuarios[100];      // Espaco para guardar ate 100 clientes
Produto catalogo[50];       // Espaco para guardar ate 50 produtos diferentes
ItemCarrinho carrinho[50];  // Espaco para guardar os itens do carrinho atual
int qtd_itens_carrinho = 0; // Variavel vital: controla quantos itens diferentes estao no carrinho

// ==========================================
// FUNCAO DE INICIALIZACAO (Mock de Dados)
// ==========================================
// Funcao responsavel por cadastrar os produtos iniciais no vetor 'catalogo'
// Isso permite testar as compras sem precisar cadastrar tudo a mao toda vez.
void inicializarSistema() {
    
    // Produto 1 - Unisex
    catalogo[0].id = 1;
    strcpy(catalogo[0].nome, "Serum Vitamina C");
    strcpy(catalogo[0].categoria, "Skincare");
    catalogo[0].preco = 89.90;
    catalogo[0].estoque = 50;

    // Produto 2 - Unisex
    catalogo[1].id = 2;
    strcpy(catalogo[1].nome, "Base Matte Alta Cobertura");
    strcpy(catalogo[1].categoria, "Maquiagem");
    catalogo[1].preco = 55.00;
    catalogo[1].estoque = 30;

    // Produto 3 - Masculino
    catalogo[2].id = 3;
    strcpy(catalogo[2].nome, "Espuma de Barbear Hidratante");
    strcpy(catalogo[2].categoria, "Cuidados Masculinos");
    catalogo[2].preco = 42.50;
    catalogo[2].estoque = 25;

    // Produto 4 - Masculino
    catalogo[3].id = 4;
    strcpy(catalogo[3].nome, "Oleo para Barba e Rosto");
    strcpy(catalogo[3].categoria, "Cuidados Masculinos");
    catalogo[3].preco = 39.90;
    catalogo[3].estoque = 20;

    // Produto 5 - Unisex
    catalogo[4].id = 5;
    strcpy(catalogo[4].nome, "Protetor Solar Toque Seco");
    strcpy(catalogo[4].categoria, "Skincare");
    catalogo[4].preco = 69.90;
    catalogo[4].estoque = 40;

    // Produto 6 - Unisex
    catalogo[5].id = 6;
    strcpy(catalogo[5].nome, "Gel de Limpeza Facial");
    strcpy(catalogo[5].categoria, "Skincare");
    catalogo[5].preco = 45.00;
    catalogo[5].estoque = 35;

    // Produto 7 - Unisex
    catalogo[6].id = 7;
    strcpy(catalogo[6].nome, "Hidratante Corporal Neutro");
    strcpy(catalogo[6].categoria, "Cuidados Corporais");
    catalogo[6].preco = 34.90;
    catalogo[6].estoque = 50;

    printf("Sistema GlowUP inicializado com sucesso!\n\n");
}

#endif
