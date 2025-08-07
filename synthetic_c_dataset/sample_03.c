#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ler_linha() {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return NULL;

    buffer[strcspn(buffer, "\n")] = '\0';
    char* linha = malloc(strlen(buffer) + 1);
    if (!linha) return NULL;

    strcpy(linha, buffer);

    if (strlen(linha) == 0) return NULL;

    return linha;
}

int main() {
    char* nome = ler_linha();

    if (nome == NULL) {
        printf("Erro ou entrada vazia.\n");
        return 1; 
    }

    printf("Você digitou: %s\n", nome);
    free(nome);
    return 0;
}
