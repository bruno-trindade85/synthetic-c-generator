#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* nome = malloc(10);
    strcpy(nome, "abc");

    char* novo = realloc(nome, 100);
    if (novo != NULL) {
        strcpy(novo + 3, "def");
        nome = novo;
    }

    printf("Nome: %s\n", nome);


    free(nome);

    return 0;
}

