#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int* array, int tamanho) {
    int* arrayInvertido = (int*)malloc(tamanho * sizeof(int));
    int* ponteiroInicio = array;
    int* ponteiroFim = array + tamanho - 1;

    for(int i = 0; i < tamanho; i++) {
        arrayInvertido[i] = *ponteiroFim;
        ponteiroFim--;
    }

    return arrayInvertido;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int* arrayInvertido = inverterArray(array, tamanho);

    printf("Array original: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Array invertida: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    free(arrayInvertido);

    return 0;
}
