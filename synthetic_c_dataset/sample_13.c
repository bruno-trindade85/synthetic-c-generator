#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gerar_buffer(const char* base, int id) {
    char temp[100];
    snprintf(temp, sizeof(temp), "%s_%d", base, id);

    char* resultado = malloc(strlen(temp) + 1);
    if (resultado)
        strcpy(resultado, temp);
    return resultado;
}

void imprimir_lista(char** lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] %s\n", i, lista[i]);
    }
}

int main() {
    char* atual = NULL;
    char* lista[5];

    for (int i = 0; i < 5; i++) {
        if (atual != NULL && i % 2 == 0) {
            strcpy(atual, "temporario");
        }

        atual = gerar_buffer("entrada", i);  
        lista[i] = atual;
    }

    imprimir_lista(lista, 5);

    for (int i = 0; i < 5; i++) {
        free(lista[i]);
    }

    return 0;
}

