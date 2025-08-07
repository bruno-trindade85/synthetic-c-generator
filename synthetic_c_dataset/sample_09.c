#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* blocos[5];
    char buffer[50];

    for (int i = 0; i < 5; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        blocos[i] = malloc(strlen(buffer) + 1);
        strcpy(blocos[i], buffer);

        if (strcmp(buffer, "parar") == 0)
            break; 
    }

    return 0;
}

