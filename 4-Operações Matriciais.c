#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int** multiplicarMatrizes(int** A, int** B, int linhas1, int colunas1, int colunas2) {
    int** resultado = alocarMatriz(linhas1, colunas2);
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return resultado;
}

int** transporMatriz(int** matriz, int linhas, int colunas) {
    int** transposta = alocarMatriz(colunas, linhas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    return transposta;
}

void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas1 = 2, colunas1 = 3;
    int linhas2 = 3, colunas2 = 2;

    int** A = alocarMatriz(linhas1, colunas1);
    int** B = alocarMatriz(linhas2, colunas2);

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    int** resultadoMultiplicacao = multiplicarMatrizes(A, B, linhas1, colunas1, colunas2);
    int** transpostaA = transporMatriz(A, linhas1, colunas1);

    printf("Matriz A:\n");
    imprimirMatriz(A, linhas1, colunas1);

    printf("Matriz B:\n");
    imprimirMatriz(B, linhas2, colunas2);

    printf("Multiplicação de A e B em matriz:\n");
    imprimirMatriz(resultadoMultiplicacao, linhas1, colunas2);

    printf("Matriz Transposta de A:\n");
    imprimirMatriz(transpostaA, colunas1, linhas1);

    liberarMatriz(A, linhas1);
    liberarMatriz(B, linhas2);
    liberarMatriz(resultadoMultiplicacao, linhas1);
    liberarMatriz(transpostaA, colunas1);

    return 0;
}
