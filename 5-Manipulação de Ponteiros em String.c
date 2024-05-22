#include <stdio.h>
#include <ctype.h>

void converterParaMaiusculas(char* str) {
    char* p = str;
    while (*p != '\0') {
        *p = toupper(*p);
        p++;
    }
}

int main() {
    char str[] = "exemplo de string";

    printf("Palavra normal(sem alterações): %s\n", str);
    converterParaMaiusculas(str);
    printf("palavra com maiúsculas: %s\n", str);

    return 0;
}
