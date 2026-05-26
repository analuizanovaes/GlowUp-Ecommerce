#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h" // Puxa as definições de Usuario e Produto
#include "posvenda.h"   // Puxa as definições e protótipos de funções do pós-venda

// Vetores Globais (Memória do Sistema)
Usuario usuarios[100];
int total_usuarios = 0; // Contador para o número de usuários cadastrados

Produto catalogo[50];
int total_produtos = 0; // Contador para o número de produtos cadastrados
Pedido pedidos[100];
int total_pedidos = 0; // Contador para o número de pedidos realizados

// Variáveis para controle de quantidades
void inicializarSistema() {
    // Produto 1
    catalogo[0].id = 1;
    strcpy(catalogo[0].nome, "Serum Vitamina C");
    strcpy(catalogo[0].categoria, "Skincare");
    catalogo[0].preco = 89.90;
    catalogo[0].estoque = 50;
    total_produtos = 5;

    // Produto 2
    catalogo[1].id = 2;
    strcpy(catalogo[1].nome, "Base Matte Alta Cobertura");
    strcpy(catalogo[1].categoria, "Maquiagem");
    catalogo[1].preco = 55.00;
    catalogo[1].estoque = 30;
    total_pedidos = 3;

    printf("Sistema GlowUP inicializado com sucesso!\n");
}

// Protótipos de funções para o menu principal (Simulações)
void cadastrarUsuario() { printf("\n>> Redirecionando para o cadastro de usuario...\n"); }
int realizarLogin() { printf("\n>> Redirecionando para o login...\n");
    return 1;
}
void exibirCarrinho() { printf("\n>> Exibindo carrinho de compras...\n"); }
void buscarProduto() { printf("\n>> Redirecionando para a busca de produtos...\n"); }
void finalizarPedido() { printf("\n>> Redirecionando para a finalização do pedido...\n"); }
void meuPerfil() { printf("\n>> Redirecionando para o perfil do usuario...\n"); }

void verCatalogoDeProdutos() {
    printf("\n>> --- CATALOGO DE PRODUTOS GLOWUP ---\n");
    printf("ID: %d | %s (%s) - R$ %.2f [Estoque: %d]\n", catalogo[0].id, catalogo[0].nome, catalogo[0].categoria, catalogo[0].preco, catalogo[0].estoque);
    printf("ID: %d | %s (%s) - R$ %.2f [Estoque: %d]\n", catalogo[1].id, catalogo[1].nome, catalogo[1].categoria, catalogo[1].preco, catalogo[1].estoque);
}

int main(void) {
    int opcao;
    // Variável para controlar o estado de login do usuário. 0 para Novo Cliente e 1 para Cliente Logado.
    int usuario_logado = 0;

    inicializarSistema();

    do {
        printf("\n===============================\n");
        printf("|       GLOWUP Ecommerce      |\n");
        printf("===============================\n");

        if (!usuario_logado) {
            // Menu do Novo Cliente (Visitante)
            printf("| 1. Criar Conta              |\n");
            printf("| 2. Fazer Login              |\n");
            printf("| 0. Sair                     |\n");
        } else {
            // Menu do Cliente Logado
            printf("| 1. Ver Catalogo             |\n");
            printf("| 2. Buscar Produto           |\n");
            printf("| 3. Ver Carrinho             |\n");
            printf("| 4. Finalizar Pedido         |\n");
            printf("| 5. Meus Pedidos/Avaliar     |\n"); // SEU MÓDULO DE PÓS-VENDA
            printf("| 6. Meu Perfil               |\n");
            printf("| 0. Sair                     |\n");
        }
        printf("===============================\n");
        printf("Escolha uma opcao: ");

        // Validação básica para garantir que a entrada seja um número inteiro
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada
            continue;
        }

        // Roteamento de escolhas baseado no estado do usuário (Garante que os números batam com os cards)
        if (!usuario_logado) {
            switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                if (realizarLogin()) {
                    usuario_logado = 1; // Atualiza o estado para Cliente Logado
                    printf("\n>> Login realizado com sucesso!\n");
                } else {
                    printf("\nFalha no Login. Tente novamente.\n");
                }
                break;
            case 0:
                printf("\n>> Saindo do programa. Obrigado por usar o GLOWUP Ecommerce!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
            }
        } else {
            switch (opcao) {
            case 1:
                verCatalogoDeProdutos();
                break;
            case 2:
                buscarProduto();
                break;
            case 3:
                exibirCarrinho();
                break;
            case 4:
                finalizarPedido();
                break;
            case 5:
                menu_pos_venda(); // Redireciona perfeitamente para o seu arquivo modular
                break;
            case 6:
                meuPerfil();
                break;
            case 0:
                usuario_logado = 0; // Retorna ao estado de Novo Cliente (Logout)
                printf("\n>> Logout realizado com sucesso!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    } while (opcao != 0 || usuario_logado == 1); // Mantém o programa rodando conforme a navegação

    return 0;
}