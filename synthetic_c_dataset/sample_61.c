#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    typedef void (*cb_t)(void*);
        typedef struct Item { cb_t cb; void* data; } Item;
        Item registry[64]; int r=0;
        for(int i=0;i<50;i++){
            void* data = malloc(40 + (i%10));
            if(!data) break;
            registry[r++] = (Item){NULL, data};
        }
    return 0;
}
