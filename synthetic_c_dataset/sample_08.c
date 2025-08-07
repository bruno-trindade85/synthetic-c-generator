#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* global;

void registrar() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    global = malloc(strlen(buffer) + 1);
    strcpy(global, buffer);
}

int main() {
    registrar();
    printf("Registrado: %s\n", global);
    
    return 0;
}

