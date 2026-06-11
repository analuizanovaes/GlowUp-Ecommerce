// ============================================================================
// ARQUIVO: main.c
// DESCRIÇÃO: Este é o arquivo principal do programa. É ele que junta o trabalho
//            de todo o grupo, exibe os menus na tela e direciona o cliente para 
//            a função certa (comprar, cadastrar, sair, etc).
// COMPILAÇÃO: gcc main.c usuarios.c catalogo.c carrinho.c checkout.c posvenda.c -o glowup ; ./glowup.exe
// ============================================================================

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
// CRIAÇÃO DAS LISTAS DE DADOS
// É como se fosse o nosso banco de dados, mas salva na memória ram
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
// COLOCAR PRODUTOS INICIAIS NA LOJA
// Assim a gente já tem o que vender logo que o programa abre para testar
// ============================================================
void inicializarSistema()
{
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
    
    catalogo[2].id = 3;
    strcpy(catalogo[2].nome, "Espuma de Barbear");
    strcpy(catalogo[2].categoria, "Cuidados");
    catalogo[2].preco = 42.50;
    catalogo[2].estoque = 25;
    
    catalogo[3].id = 4;
    strcpy(catalogo[3].nome, "Oleo para Barba e Rosto");
    strcpy(catalogo[3].categoria, "Cuidados");
    catalogo[3].preco = 39.90;
    catalogo[3].estoque = 20;
    
    catalogo[4].id = 5;
    strcpy(catalogo[4].nome, "Protetor Solar Toque Seco");
    strcpy(catalogo[4].categoria, "Skincare");
    catalogo[4].preco = 69.90;
    catalogo[4].estoque = 40;
    
    catalogo[5].id = 6;
    strcpy(catalogo[5].nome, "Gel de Limpeza Facial");
    strcpy(catalogo[5].categoria, "Skincare");
    catalogo[5].preco = 45.00;
    catalogo[5].estoque = 35;
    
    catalogo[6].id = 7;
    strcpy(catalogo[6].nome, "Hidratante Corporal");
    strcpy(catalogo[6].categoria, "Cuidados");
    catalogo[6].preco = 34.90;
    catalogo[6].estoque = 50;
    
    catalogo[7].id = 8;
    strcpy(catalogo[7].nome, "Mascara de Cilios Volume");
    strcpy(catalogo[7].categoria, "Maquiagem");
    catalogo[7].preco = 29.90;
    catalogo[7].estoque = 60;
    
    catalogo[8].id = 9;
    strcpy(catalogo[8].nome, "Batom Liquido Vermelho");
    strcpy(catalogo[8].categoria, "Maquiagem");
    catalogo[8].preco = 25.50;
    catalogo[8].estoque = 45;
    
    catalogo[9].id = 10;
    strcpy(catalogo[9].nome, "Perfume Floral EDP");
    strcpy(catalogo[9].categoria, "Perfumaria");
    catalogo[9].preco = 149.90;
    catalogo[9].estoque = 15;

    total_produtos = 10;
    
    // Banner bonitinho de abertura do nosso programa
    printf("\n");
    printf("+===================================================+\n");
    printf("|                                                   |\n");
    printf("|              BEM-VINDO AO GLOWUP                  |\n");
    printf("|                                                   |\n");
    printf("|        Sua loja de Beleza e Autocuidado           |\n");
    printf("|                                                   |\n");
    printf("+===================================================+\n");
    printf("| Sistema inicializado com sucesso!                 |\n");
    printf("+===================================================+\n");
}

// ============================================================
// CUIDAR DO LOGIN E LOGOUT (Lógica da Sthefanny)
// Função para o cliente sair da conta de forma segura
// ============================================================
void efetuarLogout(int *usuario_logado)
{
    // Tira a conta da pessoa do sistema
    *usuario_logado = -1;

    // Esvazia o carrinho para a próxima pessoa que for usar o sistema não ver as compras dos outros
    qtd_itens_carrinho = 0;
    memset(carrinho, 0, sizeof(carrinho));

    printf("\n>> [Sessao Encerrada] Logout efetuado. Carrinho de compras esvaziado por seguranca!\n");
}

// ============================================================
// FUNÇÃO PRINCIPAL (Onde o programa começa a rodar de verdade)
// ============================================================
int main()
{
    int opcao;
    int usuario_logado = -1; // Funciona como uma chave: se for -1, é visitante. Se for número, é cliente logado.

    inicializarSistema();

    // Loop infinito para manter o programa sempre rodando até a pessoa escolher a opção de sair
    while (1)
    {
        // Se a chave for -1, mostramos a tela inicial de quem não está na conta
        if (usuario_logado == -1)
        {
            // MENU INICIAL PARA VISITANTES (Design da Yasmin)
            printf("\n");
            printf("+===================================================+\n");
            printf("|                GLOWUP E-COMMERCE                  |\n");
            printf("+===================================================+\n");
            printf("| 1. Criar Conta                                    |\n");
            printf("| 2. Fazer Login                                    |\n");
            printf("| 0. Sair do Sistema                                |\n");
            printf("+===================================================+\n");
            printf("Escolha uma opcao: ");

            // Proteção feita pela Ana e pelo Marcelo!
            // O comando 'scanf' tenta ler um número. Se a pessoa digitar uma letra sem querer, 
            // a gente pega o erro aqui para o programa não travar.
            if (scanf("%d", &opcao) != 1)
            {
                printf("\n>> Erro: Digite apenas os numeros do menu.\n");
                while (getchar() != '\n'); // Limpa a sujeira do teclado
                continue;
            }
            while (getchar() != '\n');

            switch (opcao)
            {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                // Tenta fazer o login e muda o estado da nossa chave
                usuario_logado = realizarLogin();
                if (usuario_logado != -1)
                {
                    printf("\n>> Bem-vindo de volta, %s!\n", usuarios[usuario_logado].nome);
                }
                break;
            case 0:
                printf("\n>> Obrigado por usar o GlowUP! Encerrando...\n");
                return 0; // Fecha o programa
            default:
                printf("\n>> Opcao invalida.\n");
            }
        }
        else
        {
            // Se a pessoa fez login, mostramos o menu com as coisas de comprar
            printf("\n");
            printf("+===================================================+\n");
            printf("|                PAINEL DO CLIENTE                  |\n");
            printf("+===================================================+\n");
            printf("| 1. Ver Catalogo                                   |\n");
            printf("| 2. Buscar Produto                                 |\n");
            printf("| 3. Ver Carrinho / Adicionar                       |\n");
            printf("| 4. Finalizar Pedido                               |\n");
            printf("| 5. Meus Pedidos / Avaliar                         |\n");
            printf("| 6. Editar Meu Perfil                              |\n");
            printf("| 0. Deslogar                                       |\n");
            printf("+===================================================+\n");
            printf("Escolha uma opcao: ");

            // Mesma proteção para não travar na hora de escolher a opção
            if (scanf("%d", &opcao) != 1)
            {
                printf("\n>> Erro: Digite apenas os numeros do menu.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');

            switch (opcao)
            {
            case 1:
                listarProdutos();
                break;
            case 2:
                buscarProdutoPorNome();
                break;
            case 3:
                exibirCarrinho();
                break;
            case 4:
            {
                // Só deixa ir para a tela de pagamento se tiver algo no carrinho!
                if (calcularSubtotalCarrinho() > 0)
                {
                    char end[200];

                    // Pede o endereço até o cliente digitar do jeito que a gente pediu
                    while (1)
                    {
                        printf("\nEndereco (Rua X, Cidade, Brasil): ");
                        scanf(" %199[^\n]", end);

                        while (getchar() != '\n'); 

                        if (!validarEndereco(end))
                        {
                            printf(">> Erro: Formato invalido. Use: Rua X, Cidade, Brasil.\n");
                            continue;
                        }

                        break;
                    }

                    // Calcula todos os valores separadinhos
                    float subtotal = calcularSubtotalCarrinho();
                    float frete = calcularFrete(subtotal);
                    float desconto = aplicarCupom(subtotal);
                    float total = subtotal + frete - desconto;

                    // Mostra o extrato da compra para o cliente ver
                    printf("\n");
                    printf("+===================================================+\n");
                    printf("|                RESUMO DO PEDIDO                   |\n");
                    printf("+===================================================+\n");

                    printf("| Subtotal : R$ %-35.2f |\n", subtotal);
                    printf("| Frete    : R$ %-35.2f |\n", frete);
                    printf("| Desconto : R$ %-35.2f |\n", desconto);

                    printf("+---------------------------------------------------+\n");

                    printf("| TOTAL    : R$ %-35.2f |\n", total);

                    printf("+===================================================+\n");

                    // Se a simulação do pagamento der certo, salva o pedido!
                    if (processarPagamento(total))
                    {
                        faturarPedido(total, usuario_logado);
                    }
                    else
                    {
                        printf("\n>> Pedido cancelado.\n");
                    }
                }
                else
                {
                    printf(">> Carrinho vazio.\n");
                }
            }
            break;

            case 5:
                menu_pos_venda();
                break;

            case 6:
                editarDados(usuario_logado);
                break;
            case 0:
                efetuarLogout(&usuario_logado); // Sai da conta e limpa o carrinho
                break;
            default:
                printf("\n>> Opcao invalida.\n");
            }
        }
    }
    return 0; 
}