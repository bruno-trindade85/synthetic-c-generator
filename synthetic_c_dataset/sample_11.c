#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char** lista = malloc(5 * sizeof(char*));
    char buffer[100];

    for (int i = 0; i < 5; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        lista[i] = malloc(strlen(buffer) + 1);
        strcpy(lista[i], buffer);
    }

    for (int i = 0; i < 3; i++) {
        free(lista[i]);
    }

    free(lista); 

    return 0;
}

