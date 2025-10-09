#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    typedef struct Node { int v; struct Node* next; } Node;
        Node* head = NULL;
        for(int i=0;i<20;i++){ Node* n = (Node*)malloc(sizeof(Node)); if(!n){ /* cleanup on fail */ break; } n->v=i; n->next=head; head=n; }
        Node* it = head;
        while(it){ Node* nx = it->next; free(it); it = nx; }
        logi("ok");
    return 0;
}
