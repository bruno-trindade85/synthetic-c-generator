#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    size_t cap = 4, need = 64;
        int *a = (int*)malloc(cap*sizeof(int));
        if(!a) return 0;
        while(cap < need){
            size_t nc = cap * 2;
            int *tmp = (int*)realloc(a, nc*sizeof(int));
            if(!tmp){ free(a); return 0; }
            a = tmp; cap = nc;
        }
        for(size_t i=0;i<need;i++) a[i%cap] = (int)i;
        free(a);
    return 0;
}
