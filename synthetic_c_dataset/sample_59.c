#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    static char* cache[256] = {0};
        static int used = 0;
        for(int i=0;i<200;i++){
            size_t n = (size_t)(32 + (i%64));
            char *p = (char*)malloc(n);
            if(!p) break;
            memset(p, 'C', n);
            if(used < 256){ cache[used++] = p; }
        }
    return 0;
}
