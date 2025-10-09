#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *p = (char*)malloc(256);
        if(!p){ logi("alloc fail"); return 0; }
        p[0] = 'A';
        logi("work");
        /* missing free(p); */
    return 0;
}
