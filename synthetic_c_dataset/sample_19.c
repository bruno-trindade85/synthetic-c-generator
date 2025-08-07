#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char* nome;
    struct Nodo* anterior;
    struct Nodo* proximo;
} Nodo;

Nodo* inserir(Nodo* fim, const char* nome) {
    Nodo* novo = malloc(sizeof(Nodo));
    if (!novo) return fim;

    novo->nome = malloc(strlen(nome) + 1);
    if (!novo->nome) {
        free(novo);
        return fim;
    }

    strcpy(novo->nome, nome);
    novo->anterior = fim;
    novo->proximo = NULL;

    if (fim)
        fim->proximo = novo;

    return novo;
}

void imprimir(Nodo* inicio) {
    while (inicio) {
        printf("%s\n", inicio->nome);
        inicio = inicio->proximo;
    }
}

int main() {
    char entrada[100];
    Nodo *inicio = NULL, *fim = NULL;

    for (int i = 0; i < 5; i++) {
        snprintf(entrada, sizeof(entrada), "Item_%d", i);
        fim = inserir(fim, entrada);
        if (inicio == NULL) inicio = fim;
    }

    Nodo* atual = inicio;
    while (atual) {
        if (strstr(atual->nome, "2")) {
            if (atual->anterior)
                atual->anterior->proximo = atual->proximo;
            if (atual->proximo)
                atual->proximo->anterior = atual->anterior;

            
            atual = atual->proximo;  
            continue;
        }
        atual = atual->proximo;
    }

    printf("Itens restantes:\n");
    imprimir(inicio);

    atual = inicio;
    while (atual) {
        Nodo* temp = atual;
        atual = atual->proximo;
        free(temp->nome);
        free(temp);
    }

    return 0;
}

