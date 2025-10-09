#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    void my_free(void* p){ (void)p; }
        void* a = malloc(100);
        void* b = malloc(200);
        if(!a || !b) return 0;
        my_free(a); my_free(b);
    return 0;
}
