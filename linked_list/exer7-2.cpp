#include <stdio.h>
#define N 3

struct NODE{
    int key;
    struct NODE *next;
}node[N];


int main(){
    int i, delkey = 250, deleted=0;
    struct NODE *ptr, *old_ptr=NULL;

    //linked list
    node[0].key = 100;
    node[1].key = 250;
    node[2].key = 467;

    for(i=0; i<N-1; i++)
        node[i].next = &node[i+1];
    node[i].next = NULL;

    //delete data
    ptr = &node[0];
    while(ptr != NULL){
        if(ptr->key == delkey){
            old_ptr->next = ptr->next;
            ptr->next = NULL;
            deleted = 1;
            break;
        }
        old_ptr = ptr;
        ptr = ptr->next;
    }

    printf(deleted?"node deleted\n":"key not found\n");
}




