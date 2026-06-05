#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "catalogo.h"  

Usuario usuarios[100];
Produto catalogo[50];
ItemCarrinho carrinho[10];
int total_itens_carrinho = 0;

void inicializarSistema() {
    catalogo[0].id = 1;
    strcpy(catalogo[0].nome, "Serum Vitamina C");
    strcpy(catalogo[0].categoria, "Skincare");
    catalogo[0].preco = 89.90;
    catalogo[0].estoque = 50;

    catalogo[1].id = 2;
    strcpy(catalogo[1].nome, "Base Matte Alta Cobertura");
    strcpy(catalogo[1].categoria, "Maquiagem");
    catalogo[1].preco = 55.00;
    catalogo[1].estoque = 30;

    usuarios[0].id = 1;
    strcpy(usuarios[0].nome, "Sthefanny Ramos");
    strcpy(usuarios[0].cpf, "123.456.789-00");
    strcpy(usuarios[0].email, "sthefanny@email.com");
    strcpy(usuarios[0].senha, "123456");
    strcpy(usuarios[0].logradouro, "Rua das Flores");
    strcpy(usuarios[0].numero, "123");
    strcpy(usuarios[0].cidade, "Brasilia");
    strcpy(usuarios[0].uf, "DF");

    // Mock de item no carrinho para testes
    carrinho[0].id_produto = 1;
    carrinho[0].quantidade = 2;
    carrinho[0].subtotal = 179.80;
    total_itens_carrinho = 1;

    printf("Sistema GlowUP inicializado com sucesso!\n");
}

void efetuarLogout() {
    printf("\n--- EFETUANDO LOGOUT ---");
    printf("\nItens no carrinho antes do logout: %d", total_itens_carrinho);
    
    // Garante a limpeza dos dados da sessão do usuário
    total_itens_carrinho = 0;
    memset(carrinho, 0, sizeof(carrinho));
    
    printf("\n[Sessao Encerrada] Logout efetuado com sucesso. Carrinho zerado!\n");
    printf("-------------------------\n");
}

int main() {
    inicializarSistema();
    
    printf("\nItem 1 carregado: %s (Estoque: %d)\n", catalogo[0].nome, catalogo[0].estoque);
    printf("Item 2 carregado: %s (Estoque: %d)\n", catalogo[1].nome, catalogo[1].estoque);
    
    listarProdutos(2);
    buscarProdutoPorNome(2);
    
    efetuarLogout();
    
    return 0;
}
