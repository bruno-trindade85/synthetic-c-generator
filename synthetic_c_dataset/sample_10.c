#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* nome;
    struct No* prox;
} No;

int main() {
    No* inicio = NULL;

    for (int i = 0; i < 3; i++) {
        No* novo = malloc(sizeof(No));
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        novo->nome = malloc(strlen(buffer) + 1);
        strcpy(novo->nome, buffer);
        novo->prox = inicio;
        inicio = novo;
    }


    for (int i = 0; i < 2 && inicio != NULL; i++) {
        No* temp = inicio;
        inicio = inicio->prox;
        free(temp->nome);
        free(temp);
    }

    return 0;
}

