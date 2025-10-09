#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    typedef struct Ctx { void* buf; size_t n; } Ctx;
        Ctx* contexts[64] = {0};
        int c = 0;
        for(int i=0;i<64;i++){
            Ctx* ctx = (Ctx*)malloc(sizeof(Ctx));
            if(!ctx) break;
            ctx->n = (size_t)(i+1)*16;
            ctx->buf = malloc(ctx->n);
            if(!ctx->buf){ return 0; }
            contexts[c++] = ctx;
        }
    return 0;
}
