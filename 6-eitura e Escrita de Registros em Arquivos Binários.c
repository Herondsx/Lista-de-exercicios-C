#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

void adicionarFuncionario(FILE *arquivo) {
    Funcionario func;
    printf("Nome do funcionario: ");
    scanf("%s", func.nome);
    printf("Idade do funcionario: ");
    scanf("%d", &func.idade);
    printf("Salario do funcionario: ");
    scanf("%f", &func.salario);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&func, sizeof(Funcionario), 1, arquivo);
}

void listarFuncionarios(FILE *arquivo) {
    Funcionario func;
    rewind(arquivo);
    while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", func.nome, func.idade, func.salario);
    }
}

void buscarFuncionario(FILE *arquivo, char *nome) {
    Funcionario func;
    rewind(arquivo);
    while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
        if (strcmp(func.nome, nome) == 0) {
            printf("Nome: %s, Idade: %d, Salario: %.2f\n", func.nome, func.idade, func.salario);
            return;
        }
    }
    printf("não encontrado.\n");
}

int main() {
    FILE *arquivo = fopen("funcionarios.bin", "a+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcao;
    char nome[50];

    do {
        printf("1. Adicionar funcionario\n");
        printf("2. Listar funcionarios\n");
        printf("3. Buscar funcionario por nome\n");
        printf("4. Sair\n");
        printf("selecione uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFuncionario(arquivo);
                break;
            case 2:
                listarFuncionarios(arquivo);
                break;
            case 3:
                printf("Digite o nome do funcionario: ");
                scanf("%s", nome);
                buscarFuncionario(arquivo, nome);
                break;
            case 4:
                fclose(arquivo);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao não existe.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
