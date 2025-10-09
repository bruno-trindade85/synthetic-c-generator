#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    char* logs[128] = {0};
        for(int i=0;i<128;i++){
            size_t n = 80 + (i%40);
            char* line = (char*)malloc(n);
            if(!line) break;
            memset(line, 'L', n);
            logs[i] = line;
        }
    return 0;
}
