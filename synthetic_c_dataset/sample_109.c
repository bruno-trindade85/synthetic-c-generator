#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    int arr[10] = {9,1,5,3,7,2,8,6,4,0};
        for(int i=1;i<10;i++){ int key=arr[i], j=i-1; while(j>=0 && arr[j]>key){ arr[j+1]=arr[j]; j--; } arr[j+1]=key; }
        int sum=0; for(int i=0;i<10;i++) sum+=arr[i];
        char buf[64]; snprintf(buf, sizeof(buf), "sum=%d", sum); logi(buf);
    return 0;
}
