#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    for(int i = 0; i < 1000000; i++) {
        int x = i * i;
    }

    fim = clock();

    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f em segundos\n", tempo_gasto);

    return 0;
}
