#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    for(int i=0;i<100;i++){
            char *b = (char*)malloc(32);
            if(!b) break;
            b[0] = (char)(i & 0x7F);
            /* no free(b); leak each iter */
        }
    return 0;
}
