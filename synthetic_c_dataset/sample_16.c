#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRADAS 10
#define TAM_BUFFER 100

int main() {
    char* entradas[MAX_ENTRADAS];
    int total = 0;
    char buffer[TAM_BUFFER];

    for (int i = 0; i < MAX_ENTRADAS; i++) {
        printf("Digite o valor #%d (ou 'cancelar'): ", i + 1);
        if (fgets(buffer, TAM_BUFFER, stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "cancelar") == 0)
            break;

        entradas[i] = malloc(strlen(buffer) + 1);
        if (entradas[i] == NULL)
            break;

        strcpy(entradas[i], buffer);
        total++;
    }

    printf("\nEntradas confirmadas:\n");
    for (int i = 0; i < total; i++) {
        printf("%s\n", entradas[i]);
        free(entradas[i]);
    }

    return 0;
}

