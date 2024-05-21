#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int n;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    struct Produto *produtos = (struct Produto *)malloc(n * sizeof(struct Produto));
    if (produtos == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Cadastro do produto %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", produtos[i].nome);

        printf("Preço: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade no estoque: ");
        scanf("%d", &produtos[i].quantidade);

        printf("\n");
    }

    float valor_total = 0;
    for (int i = 0; i < n; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);

        float valor_produto = produtos[i].preco * produtos[i].quantidade;
        valor_total += valor_produto;

        printf("Valor em estoque: %.2f\n", valor_produto);
        printf("\n");
    }

    printf("Valor total em estoque: %.2f\n", valor_total);

    free(produtos);

    return 0;
}
