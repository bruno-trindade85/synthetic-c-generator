#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* nomes[2];
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    nomes[0] = malloc(strlen(buffer) + 1);
    strcpy(nomes[0], buffer);

    
    nomes[1] = nomes[0];

    free(nomes[0]);  
    

    return 0;
}

