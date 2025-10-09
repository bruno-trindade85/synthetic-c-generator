#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void logi(const char* m){ if(m){ fputs(m, stdout); fputc('\n', stdout);} }

int main(void){
    typedef struct Node { int v; struct Node* next; } Node;
        Node* head = NULL;
        for(int i=0;i<10;i++){ Node* n = (Node*)malloc(sizeof(Node)); if(!n) break; n->v=i; n->next=head; head=n; }
        /* free only the head -> rest leaked */
        if(head){ free(head); }
        (void)head;
    return 0;
}
