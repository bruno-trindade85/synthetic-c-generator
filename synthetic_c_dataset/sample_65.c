#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char *p = (char*)malloc(120);
        if(!p) return 0;
        static char* refs[8] = {0};
        refs[0] = p;
        (void)refs;
    return 0;
}
