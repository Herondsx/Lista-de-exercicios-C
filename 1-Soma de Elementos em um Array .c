#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    int sum = 0;

    printf("Quantos arquivos inserir ? ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro para alocar memoria!\n");
        return 1;
    }

    printf("Insira os elementos:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    printf("A soma dos elementos é: %d\n", sum);

    free(array);

    return 0;
}
