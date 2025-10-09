#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *buf = (char*)malloc(128);
        if(!buf) return 0;
        if ((unsigned)(rand()) % 2u == 0u){
            logi("early exit");
            return 0; /* buf leaked on this path */
        }
        free(buf);
    return 0;
}
