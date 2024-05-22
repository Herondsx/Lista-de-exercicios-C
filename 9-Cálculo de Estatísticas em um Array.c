#include <stdio.h>
#include <stdlib.h>

double media(int* array, int tamanho) {
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma / tamanho;
}

double mediana(int* array, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    if(tamanho % 2 == 0) {
        return (array[tamanho/2 - 1] + array[tamanho/2]) / 2.0;
    } else {
        return array[tamanho/2];
    }
}

int moda(int* array, int tamanho) {
    int maxCount = 0, moda = -1, i, j;

    for (i = 0; i < tamanho; ++i) {
        int count = 0;

        for (j = 0; j < tamanho; ++j) {
            if (array[j] == array[i])
            ++count;
        }

        if (count > maxCount) {
            maxCount = count;
            moda = array[i];
        }
    }

    return moda;
}

int main() {
    int array[] = {1, 2, 3, 2, 1};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Média: %.2f\n", media(array, tamanho));
    printf("Mediana: %.2f\n", mediana(array, tamanho));
    printf("Moda: %d\n", moda(array, tamanho));

    return 0;
}
