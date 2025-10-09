#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    static void* thread_data[32] = {0};
        for(int t=0;t<16;t++){
            size_t n = 48u + (unsigned)(t*11u % 32u);
            void* block = malloc(n);
            if(!block) break;
            thread_data[t] = block;
        }
    return 0;
}
