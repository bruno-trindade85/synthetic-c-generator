#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    scanf("%d", &x);

    char* texto = NULL;

    if (x % 2 == 0) {
        texto = malloc(100);
    }

    if (x > 10) {
        printf("Valor alto\n");
        return 0; 
    }

    if (texto) {
        free(texto);
    }

    return 0;
}

