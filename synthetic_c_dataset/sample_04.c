#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* dado;
    struct No* prox;
} No;

int main() {
    No* cabeca = NULL;
    char buffer[100];

    for (int i = 0; i < 3; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        No* novo = malloc(sizeof(No));
        novo->dado = malloc(strlen(buffer) + 1);
        strcpy(novo->dado, buffer);

        novo->prox = cabeca;
        cabeca = novo;
    }

   
    if (cabeca) {
        cabeca = cabeca->prox;  
    }

    while (cabeca) {
        No* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp->dado);
        free(temp);
    }

    return 0;
}

