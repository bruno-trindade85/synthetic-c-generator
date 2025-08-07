#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 10
#define TAM_NOME 100

int main() {
    char* nomes[MAX_NOMES];
    int total = 0;
    char buffer[TAM_NOME];

    printf("Digite até %d nomes (ou 'fim' para encerrar):\n", MAX_NOMES);
    while (total < MAX_NOMES) {
        printf("Nome %d: ", total + 1);
        if (fgets(buffer, TAM_NOME, stdin) == NULL) break;

        buffer[strcspn(buffer, "\n")] = '\0'; // remove '\n'

        if (strcmp(buffer, "fim") == 0)
            break;

        nomes[total] = (char*)malloc(strlen(buffer) + 1);
        if (nomes[total] == NULL) {
            printf("Erro de alocação.\n");
            break;
        }
        strcpy(nomes[total], buffer);
        total++;
    }

    // Substitui nomes duplicados por uma nova entrada do usuário
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(nomes[i], nomes[j]) == 0) {
                printf("Nome duplicado encontrado: %s\n", nomes[j]);
                printf("Digite um novo nome para substituir: ");
                if (fgets(buffer, TAM_NOME, stdin) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    nomes[j] = (char*)malloc(strlen(buffer) + 1);
                    if (nomes[j] != NULL) {
                        strcpy(nomes[j], buffer);
                    }
                }
            }
        }
    }

    printf("\nNomes cadastrados:\n");
    for (int i = 0; i < total; i++) {
        printf("%s\n", nomes[i]);
        free(nomes[i]);
    }

    return 0;
}
