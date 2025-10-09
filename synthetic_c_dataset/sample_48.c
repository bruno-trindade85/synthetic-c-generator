#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    void* keep[64] = {0};
        for(int i=0;i<1000;i++){
            size_t sz = (size_t)((i*37)%128 + 16);
            char *p = (char*)malloc(sz);
            if(!p) break;
            p[0] = (char)(i & 0x7F);
            if(i % 17 == 0){
                keep[i % 64] = p; /* never freed -> retained */
            } else {
                free(p);
            }
        }
    return 0;
}
