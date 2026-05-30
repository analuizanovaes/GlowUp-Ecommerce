void lerIdade() {
    int idade;
    printf("Digite sua idade: ");

    // Nova estrutura padronizada
    if (scanf("%d", &idade) != 1) {
        printf(">> Erro: Entrada invalida. Digite apenas numeros.\n");
        while (getchar() != '\n'); // Limpa o buffer (a letra)
        return;                    // Encerra a função
    }
    while (getchar() != '\n');     // Limpa o ENTER do buffer

    printf("Idade cadastrada: %d\n", idade);
}

int main() {
    int opcao;

    while (1) {
        printf("Escolha uma opcao (1 a 5): ");

        // Nova estrutura padronizada
        if (scanf("%d", &opcao) != 1) {
            printf(">> Erro: Entrada invalida. Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa a letra do teclado
            continue;                  // Volta para o início do loop
        }
        while (getchar() != '\n');     // Limpa o ENTER da memória

        // Processa a opção válida
        if (opcao == 5) break; 
    }
    return 0;
}
