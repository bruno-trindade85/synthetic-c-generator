#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    void* p = malloc(200);
        if(!p) return 0;
        /* wrong deallocator path: not freeing at all */
        (void)p;
    return 0;
}
