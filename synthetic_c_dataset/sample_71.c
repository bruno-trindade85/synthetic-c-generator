#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    FILE *f = fopen("clean_io.txt", "w");
        if(!f) return 0;
        fputs("hello clean\n", f);
        int rc = fclose(f);
        (void)rc;
    return 0;
}
