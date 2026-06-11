# 💄 Projeto GlowUp - E-commerce de Cosméticos

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/gcc-%231A2C37.svg?style=for-the-badge&logo=gnu&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluído-success?style=for-the-badge)

Bem-vindo ao repositório do **GlowUp**, um sistema de e-commerce desenvolvido como requisito parcial para a disciplina de Projeto Integrador de Programação Estruturada do Centro Universitário Euroamericano (UNIEURO).

## 🎯 Objetivo do Projeto
O sistema GlowUp foi idealizado como uma plataforma de e-commerce sólida e confiável, voltada para a venda de cosméticos. O principal objetivo é proporcionar ao consumidor uma experiência de compra intuitiva, garantindo que regras de negócio, como controle de estoque e validação financeira, sejam rigorosamente atendidas em segundo plano.

## 💻 Tecnologias e Arquitetura do Sistema
O projeto foi construído inteiramente na linguagem **C**, aplicando rigidamente os conceitos de Programação Estruturada. 

* **Escopo Acadêmico:** Focado nas bases estruturais da linguagem, o sistema **NÃO** utiliza Programação Orientada a Objetos (POO), bancos de dados reais ou frameworks externos.
* **Armazenamento Volátil:** Os dados de usuários, catálogo de produtos e histórico de pedidos são manipulados em memória RAM através de *Structs* e Vetores.
* **Modularização Avançada:** O código fonte foi projetado em múltiplos arquivos (`.c` e `.h`) para garantir isolamento de escopo, clareza e facilidade de integração em equipe. 
* **Domínios Separados:** A arquitetura utiliza `estruturas.h` e `variaveis_globais.h` para a memória central, enquanto cada funcionalidade principal da loja tem seu próprio módulo de controle (`usuarios.c`, `catalogo.c`, `carrinho.c`, `checkout.c` e `posvenda.c`).

## 🚀 Como Executar o Projeto
Para testar a aplicação localmente, certifique-se de ter um compilador da linguagem C (como o **GCC**) instalado na sua máquina.

1. Clone este repositório ou faça o download dos arquivos.
2. Abra o terminal na raiz da pasta do projeto.
3. Compile todos os módulos integrados declarando exatamente a lista de arquivos abaixo:

```bash
gcc main.c usuarios.c catalogo.c carrinho.c checkout.c posvenda.c -o glowup

```

4. Execute o sistema recém-compilado:

* **No Windows:**

```bash
.\glowup.exe

```

* **No Linux/Mac:**

```bash
./glowup

```

## 🛒 Funcionalidades Principais

O escopo da nossa aplicação abrange todo o fluxo essencial de um comércio eletrônico:

* **Gestão de Conta:** Cadastro de novos usuários, sistema de login seguro e gerenciamento de dados cadastrais com endereço de entrega.
* **Experiência de Compra:** Navegação completa pelo catálogo de cosméticos, busca integrada por nome ou categoria e adição dinâmica de itens ao carrinho de compras.
* **Checkout e Pagamento:** Consolidação do pedido, validação logística de endereço, aplicação de cupons de desconto e processamento simulado de pagamentos via PIX, Boleto ou Cartão.
* **Pós-Venda:** Consulta e acompanhamento do status de entrega do pedido e sistema de avaliação dos produtos adquiridos.
* **Controle Logístico:** Baixa automatizada de itens no inventário em tempo real e geração de faturamento com número exclusivo de pedido.

## 👥 Equipe de Desenvolvimento

Projeto construído de forma colaborativa pelas turmas ADS03M1 e SI03M1:

* [Ana Luiza Fernandes Novaes](https://github.com/analuizanovaes)
* [Emerson Júnior de Santana Oliveira Leite](https://github.com/emersonjuniorgit)
* [Maria Luiza Vicente da Silva Lacerda](https://github.com/Ma-Luh)
* [Marcelo Leitão e Silva Filho](marleitaofilho-hue)
* [Sthefanny Ramos Parrini](https://github.com/Sthef93)
* [Yasmin Gomes de Matos](https://github.com/yasminmatosg)

**Orientador:** Prof. Paulo Augusto

**Instituição:** UNIEURO - Brasília, 2026
