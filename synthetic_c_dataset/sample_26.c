#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *p = (char*)malloc(64);
        if(!p){ return 0; }
        char *q = (char*)malloc(32);
        if(!q){ /* leak p if q fails intentionally */ return 0; }
        /* overwrite p without free -> p lost */
        p = q;
        /* we still free current p (which is q), but original p leaked */
        free(p);
    return 0;
}
