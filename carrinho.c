// ============================================================
// ARQUIVO: carrinho.c
// DESCRIÇÃO: Onde o código guarda os itens que o cliente separou 
//            para comprar. Antes de colocar no carrinho, ele confere 
//            se tem estoque suficiente. E calcula quanto deu até agora.
// AUTORES: Grupo GlowUP
// ============================================================

#include <stdio.h>
#include <string.h>
#include "carrinho.h"
#include "variaveis_globais.h"

// Mostra na tela tudo que o cliente já colocou no carrinho, olhando o catálogo 
// para escrever o nome bonito do produto e o preço.
void exibirCarrinho()
{
    int opcao;

    printf("\n");
    printf("+===================================================+\n");
    printf("|                   SEU CARRINHO                    |\n");
    printf("+===================================================+\n");

    if (qtd_itens_carrinho == 0)
    {
        printf("| O carrinho esta vazio.                            |\n");
    }
    else
    {
        float total = 0;

        for (int i = 0; i < qtd_itens_carrinho; i++)
        {
            // Cruza o ID do item do carrinho com o catálogo para pegar o Nome dele
            for (int j = 0; j < total_produtos; j++)
            {
                if (catalogo[j].id == carrinho[i].id_produto)
                {
                    printf("| %2d. %-45s |\n",
                           i + 1,
                           catalogo[j].nome);

                    printf("|     Qtd: %-3d  Valor: R$ %-26.2f|\n",
                           carrinho[i].quantidade,
                           carrinho[i].subtotal);

                    printf("+---------------------------------------------------+\n");

                    break;
                }
            }

            total += carrinho[i].subtotal; // Vai somando o preço total
        }

        printf("| SUBTOTAL: R$ %-36.2f |\n", total);
    }

    printf("+===================================================+\n");
    printf("| 1. Adicionar produto ao carrinho                  |\n");
    printf("| 0. Voltar ao menu principal                       |\n");
    printf("+===================================================+\n");

    printf("Opcao: ");

    if (scanf("%d", &opcao) != 1)
    {
        while (getchar() != '\n')
            ;
        return;
    }

    while (getchar() != '\n')
        ;

    // Atalho: já pergunta direto qual item quer adicionar
    if (opcao == 1)
    {
        int id_prod, qtd;

        printf("\nID do produto: ");
        scanf("%d", &id_prod);

        printf("Quantidade: ");
        scanf("%d", &qtd);

        while (getchar() != '\n');

        // Não deixa a pessoa tentar comprar zero ou negativo
        if (qtd <= 0)
        {
            printf("\n>> Erro: A quantidade deve ser maior que zero.\n");
            return;
        }

        adicionarProdutoCarrinho(id_prod, qtd);
    }
}

// Olha se tem estoque e depois guarda o item na lista do carrinho
void adicionarProdutoCarrinho(int id, int qtd)
{
    for (int i = 0; i < total_produtos; i++)
    {
        // Se achou o ID do produto no nosso catálogo...
        if (catalogo[i].id == id)
        {
            // 1. Vê se a pessoa já tinha colocado esse mesmo produto no carrinho antes
            int indice_no_carrinho = -1;
            for (int k = 0; k < qtd_itens_carrinho; k++)
            {
                if (carrinho[k].id_produto == id)
                {
                    indice_no_carrinho = k;
                    break; // Achou!
                }
            }

            // 2. Calcula quanto a pessoa quer no total (o que já tinha + o que ela quer por agora)
            int qtd_total_desejada = qtd;
            if (indice_no_carrinho != -1)
            {
                qtd_total_desejada += carrinho[indice_no_carrinho].quantidade;
            }

            // 3. Confere se temos isso tudo no estoque
            if (catalogo[i].estoque >= qtd_total_desejada)
            {
                if (indice_no_carrinho != -1)
                {
                    // Se já estava no carrinho, só atualiza a quantidade e o subtotal
                    carrinho[indice_no_carrinho].quantidade = qtd_total_desejada;
                    carrinho[indice_no_carrinho].subtotal = qtd_total_desejada * catalogo[i].preco;
                }
                else
                {
                    // Se é um item novo, cria uma linha nova no nosso carrinho
                    carrinho[qtd_itens_carrinho].id_produto = id;
                    carrinho[qtd_itens_carrinho].quantidade = qtd;
                    carrinho[qtd_itens_carrinho].subtotal = qtd * catalogo[i].preco;
                    qtd_itens_carrinho++;
                }
                printf(">> Sucesso: Produto adicionado ao carrinho!\n");
            }
            else
            {
                printf(">> Erro: Estoque insuficiente. Temos apenas %d unidades disponiveis.\n", catalogo[i].estoque);
            }
            return;
        }
    }
    printf(">> Erro: Produto nao encontrado no catalogo.\n");
}

// Vai passando por cada item do carrinho e somando o valor de todos eles
float calcularSubtotalCarrinho()
{
    float subtotal = 0.0;
    for (int i = 0; i < qtd_itens_carrinho; i++)
    {
        subtotal += carrinho[i].subtotal;
    }
    return subtotal;
}