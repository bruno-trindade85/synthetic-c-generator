#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }
static char *gmem = NULL;

static void init_once(void){
    if(!gmem){ gmem = (char*)malloc(100); if(gmem) gmem[0]='X'; }
}

int main(void){
    init_once();
    logi("run");
    /* no free(gmem); */
    return 0;
}
