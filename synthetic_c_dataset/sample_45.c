#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    size_t cap = 8;
        int *a = (int*)malloc(cap * sizeof(int));
        if(!a) return 0;
        /* risk: direct assign, if realloc fails, original 'a' is lost */
        cap *= 1024*1024;
        a = (int*)realloc(a, cap * sizeof(int));
        if(!a){ /* lost original pointer -> leak */ return 0; }
        free(a);
    return 0;
}
