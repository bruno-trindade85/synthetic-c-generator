#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *a = (char*)malloc(64);
        if(!a) return 0;
        char *b = (char*)malloc(64);
        if(!b) goto fail;
        free(b); free(a);
        return 0;
    fail:
        return 0; /* a leaked */
    return 0;
}
