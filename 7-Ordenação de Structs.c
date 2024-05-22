#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int idade;
    float salario;
} Funcionario;

int compararIdade(const void *a, const void *b) {
    return ((Funcionario*)a)->idade - ((Funcionario*)b)->idade;
}

void imprimirFuncionarios(Funcionario funcionarios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
}

int main() {
    Funcionario funcionarios[4] = {
        {"Heron", 30, 5000.0},
        {"João", 25, 4600.0},
        {"Daniel", 35, 5300.0},
        {"Rafael", 28, 4300.0}
    };
    int n = 4;

    printf("Funcionarios antes da ordenação:\n");
    imprimirFuncionarios(funcionarios, n);

    qsort(funcionarios, n, sizeof(Funcionario), compararIdade);

    printf("\nFuncionarios depois da ordenação por idade:\n");
    imprimirFuncionarios(funcionarios, n);

    return 0;
}
