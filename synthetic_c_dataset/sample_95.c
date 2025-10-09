#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *s = (char*)malloc(64);
        if(!s) return 0;
        strcpy(s, "abc");
        strcat(s, "def");
        if(strlen(s) < 64){ /* safe */ }
        free(s);
    return 0;
}
