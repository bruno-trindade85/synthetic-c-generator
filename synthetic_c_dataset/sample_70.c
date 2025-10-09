#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    typedef struct Obj { struct Obj* ref; int id; } Obj;
        Obj* a = (Obj*)malloc(sizeof(Obj));
        Obj* b = (Obj*)malloc(sizeof(Obj));
        if(!a || !b) return 0;
        a->ref = b; b->ref = a;
    return 0;
}
