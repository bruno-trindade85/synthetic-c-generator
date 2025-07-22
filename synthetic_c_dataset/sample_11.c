#include <stdlib.h>
#include <stdio.h>

void exemplo() {
    char *buffer = (char *)malloc(100);
    if (buffer == NULL) return;
    printf("Usando o buffer...\n");
}

int main() {
    exemplo();
    return 0;
}
