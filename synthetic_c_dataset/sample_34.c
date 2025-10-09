#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    FILE *f = fopen("temp_vmi07.txt", "w");
        if(!f) return 0;
        fputs("hello", f);
        /* missing fclose(f); -> resource leak */
    return 0;
}
