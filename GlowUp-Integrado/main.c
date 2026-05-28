// ============================================================
// ARQUIVO: main.c
// MÓDULO: Ponto de Entrada e Orquestrador do Sistema
// COMPILAÇÃO: gcc main.c usuarios.c catalogo.c carrinho.c checkout.c posvenda.c -o glowup
// AUTORES: Grupo GlowUP
// ============================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"        
#include "variaveis_globais.h" 
#include "usuarios.h"          
#include "catalogo.h"          
#include "carrinho.h"          
#include "checkout.h"          
#include "posvenda.h"          

// ============================================================
// DEFINIÇÃO DA MEMÓRIA GLOBAL DO SISTEMA
// ============================================================
Usuario usuarios[100];         
int totalUsuarios = 0;         

Produto catalogo[50];          
int total_produtos = 0;        

ItemCarrinho carrinho[50];     
int qtd_itens_carrinho = 0;    

Pedido pedidos[100];           
int total_pedidos = 0;         

// ============================================================
// FUNÇÃO: inicializarSistema
// ============================================================
void inicializarSistema() {
    catalogo[0].id = 1;  strcpy(catalogo[0].nome, "Serum Vitamina C");          strcpy(catalogo[0].categoria, "Skincare");    catalogo[0].preco = 89.90;  catalogo[0].estoque = 50;
    catalogo[1].id = 2;  strcpy(catalogo[1].nome, "Base Matte Alta Cobertura"); strcpy(catalogo[1].categoria, "Maquiagem");   catalogo[1].preco = 55.00;  catalogo[1].estoque = 30;
    catalogo[2].id = 3;  strcpy(catalogo[2].nome, "Espuma de Barbear");         strcpy(catalogo[2].categoria, "Cuidados");    catalogo[2].preco = 42.50;  catalogo[2].estoque = 25;
    catalogo[3].id = 4;  strcpy(catalogo[3].nome, "Oleo para Barba e Rosto");   strcpy(catalogo[3].categoria, "Cuidados");    catalogo[3].preco = 39.90;  catalogo[3].estoque = 20;
    catalogo[4].id = 5;  strcpy(catalogo[4].nome, "Protetor Solar Toque Seco"); strcpy(catalogo[4].categoria, "Skincare");    catalogo[4].preco = 69.90;  catalogo[4].estoque = 40;
    catalogo[5].id = 6;  strcpy(catalogo[5].nome, "Gel de Limpeza Facial");     strcpy(catalogo[5].categoria, "Skincare");    catalogo[5].preco = 45.00;  catalogo[5].estoque = 35;
    catalogo[6].id = 7;  strcpy(catalogo[6].nome, "Hidratante Corporal");       strcpy(catalogo[6].categoria, "Cuidados");    catalogo[6].preco = 34.90;  catalogo[6].estoque = 50;
    catalogo[7].id = 8;  strcpy(catalogo[7].nome, "Mascara de Cilios Volume");  strcpy(catalogo[7].categoria, "Maquiagem");   catalogo[7].preco = 29.90;  catalogo[7].estoque = 60;
    catalogo[8].id = 9;  strcpy(catalogo[8].nome, "Batom Liquido Vermelho");    strcpy(catalogo[8].categoria, "Maquiagem");   catalogo[8].preco = 25.50;  catalogo[8].estoque = 45;
    catalogo[9].id = 10; strcpy(catalogo[9].nome, "Perfume Floral EDP");        strcpy(catalogo[9].categoria, "Perfumaria");  catalogo[9].preco = 149.90; catalogo[9].estoque = 15;

    total_produtos = 10; 

    printf(">> Sistema GlowUP inicializado com sucesso!\n");
}

void exibirBoasVindas() {
    printf("\n");
    printf("================================================\n");
    printf("|                                              |\n");
    printf("|           Bem-vindo ao GLOWUP!                |\n");
    printf("|        Sua loja de beleza online             |\n");
    printf("|                                              |\n");
    printf("================================================\n");
    printf("\n");
}

void exibirMenuDeslogado() {
    printf("\n===============================\n");
    printf("|       GLOWUP Ecommerce      |\n");
    printf("===============================\n");
    printf("| 1. Criar Conta              |\n");
    printf("| 2. Fazer Login              |\n");
    printf("| 0. Sair                     |\n");
    printf("===============================\n");
    printf("Escolha uma opcao: ");
}

void exibirMenuLogado() {
    printf("\n===============================\n");
    printf("|       GLOWUP Ecommerce      |\n");
    printf("===============================\n");
    printf("| 1. Ver Catalogo             |\n");
    printf("| 2. Buscar Produto           |\n");
    printf("| 3. Ver Carrinho             |\n");
    printf("| 4. Finalizar Pedido         |\n");
    printf("| 5. Meus Pedidos/Avaliar     |\n");
    printf("| 6. Editar Meu Perfil               |\n");
    printf("| 0. Sair                     |\n");
    printf("===============================\n");
    printf("Escolha uma opcao: ");
}

// ============================================================
// FUNÇÃO PRINCIPAL
// ============================================================
int main(void) {
    int opcao;
    int usuario_logado = 0;   
    int indice_cliente = -1;  

    exibirBoasVindas();   
    inicializarSistema(); 

    do {
        if (!usuario_logado) {
            exibirMenuDeslogado();
        } else {
            exibirMenuLogado();
        }

        if (scanf("%d", &opcao) != 1) {
            printf("\n>> Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        if (!usuario_logado) {
            switch (opcao) {

            case 1: 
                cadastrarUsuario(); 
                break;

            case 2: 
                indice_cliente = realizarLogin();
                if (indice_cliente != -1) {
                    usuario_logado = 1; 
                    printf("\n>> Login realizado com sucesso!\n");
                }
                break;

            case 0: 
                printf("\n>> Obrigado por usar o GLOWUP Ecommerce!\n\n");
                break;

            default:
                printf("\n>> Opcao invalida. Tente novamente.\n");
            }

        } else {
            switch (opcao) {

            case 1: 
                listarProdutos();
                break;

            case 2: 
                buscarProdutoPorNome();
                break;

            case 3: { 
                exibirCarrinho();

                int acao_carrinho;
                printf("\nDeseja adicionar um produto?\n");
                printf("1 - Sim   0 - Voltar\n");
                printf("Escolha: ");

                if (scanf("%d", &acao_carrinho) != 1) {
                    while (getchar() != '\n');
                    break;
                }

                if (acao_carrinho == 1) {
                    int id, qtd;
                    printf("\n--- ADICIONAR AO CARRINHO ---\n");
                    printf("ID do Produto: ");  scanf("%d", &id);
                    printf("Quantidade:    ");  scanf("%d", &qtd);
                    adicionarProdutoCarrinho(id, qtd); 
                }
                break;
            }

            case 4: { 
                float subtotal = calcularSubtotalCarrinho();

                if (subtotal == 0) {
                    printf("\n>> Seu carrinho esta vazio! Adicione produtos antes de finalizar.\n");
                } else {
                    char endereco_cliente[200];
                    printf("\nDigite o endereco de entrega\n");
                    printf("(Ex: Rua X, Brasilia, Brasil): ");
                    scanf(" %[^\n]", endereco_cliente);

                    if (validarEndereco(endereco_cliente)) {
                        float frete    = calcularFrete(subtotal);      
                        float desconto = aplicarCupom(subtotal);       
                        float total_final = subtotal + frete - desconto;

                        if (processarPagamento(total_final)) {
                            faturarPedido(total_final, indice_cliente);
                        }
                    }
                }
                break;
            }

            case 5: 
                menu_pos_venda(); 
                break;

            case 6: 
                editarDados(indice_cliente);
                break;

            case 0: 
                usuario_logado = 0;
                indice_cliente = -1; 
                printf("\n>> Logout realizado com sucesso!\n");
                break;

            default:
                printf("\n>> Opcao invalida. Tente novamente.\n");
            }
        }

    } while (opcao != 0 || usuario_logado == 1);

    return 0; 
}