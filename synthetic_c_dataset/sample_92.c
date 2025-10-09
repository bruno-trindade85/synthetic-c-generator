#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    size_t rows = 10, cols = 20;
        int **m = (int**)malloc(rows * sizeof(int*));
        if(!m) return 0;
        int ok = 1;
        for(size_t r=0;r<rows;r++){ m[r] = (int*)malloc(cols*sizeof(int)); if(!m[r]){ ok=0; break; } }
        if(!ok){
            for(size_t r=0;r<rows;r++){ if(m[r]) free(m[r]); }
            free(m);
            return 0;
        }
        for(size_t r=0;r<rows;r++) for(size_t c=0;c<cols;c++) m[r][c]=(int)(r*c);
        for(size_t r=0;r<rows;r++){ free(m[r]); }
        free(m);
    return 0;
}
