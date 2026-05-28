# 💄 Projeto GlowUp - E-commerce de Cosméticos

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

```

gcc main.c usuarios.c catalogo.c carrinho.c checkout.c posvenda.c -o glowup

```
4. Execute o sistema recém-compilado:
   ```bash
   # No Windows
   .\glowup.exe
   
   # No Linux/Mac
   ./glowup

```

## 🛒 Funcionalidades Principais (Backlog)

As seguintes Histórias de Usuário (HUs) compõem o escopo da nossa aplicação:

* **Gestão de Conta:** Cadastro (HU01), Login (HU02) e Gerenciamento de Dados Cadastrais (HU03).
* **Experiência de Compra:** Busca de produtos no catálogo (HU04) e adição de itens ao carrinho (HU05).
* **Checkout e Pagamento:** Finalização do pedido com validação de endereço (HU06) e processamento simulado de pagamento via PIX, Boleto ou Cartão (HU07).
* **Pós-Venda:** Acompanhamento de entrega (HU08) e avaliação de compra (HU09).
* **Controle Financeiro e Logístico:** Simulação de Gateway de Pagamento e faturamento de compras com geração de número de pedido (HG01 e HG02).

## 👥 Equipe de Desenvolvimento

Projeto construído de forma colaborativa pelas turmas ADS03M1 e SI03M1:

* Ana Luiza Fernandes Novaes
* Emerson Júnior de Santana Oliveira Leite
* Maria Luiza Vicente da Silva Lacerda
* Marcelo Leitão e Silva Filho
* Sthefanny Ramos Parrini
* Yasmin Gomes de Matos

**Orientador:** Prof. Paulo Augusto

**Instituição:** UNIEURO - Brasília, 2026
