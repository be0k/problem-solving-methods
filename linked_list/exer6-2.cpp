#include <stdio.h>
#define N 5
struct NODE{
    int key;
    struct NODE *next;
}node[N];


int main(){
    int i, newkey, fail=-1;
    struct NODE *ptr, *old_ptr=NULL;

    //linked list
    node[0].key = 100;
    node[1].key = 250;
    node[2].key = 300;
    node[3].key = 467;
    node[4].key = newkey = 500;

    for(i=0; i<N-2; i++)
        node[i].next = &node[i+1];
    node[i].next = NULL;

    //insert data
    ptr = &node[0];
    while(ptr != NULL){
        if(ptr->key == newkey){
            printf("key already exists");
            fail=0;
            break;
        }
        if(ptr->key < newkey){
                old_ptr = ptr;
                ptr = ptr-> next;

        }
        else{
            old_ptr->next = &node[4];
            node[4].next = ptr;
            fail=0;
            printf("key inserted");
            break;
        }
    }

    //not inserted
    if(fail){
    node[4].next = NULL;
    old_ptr->next = &node[4];
    }

    ptr = &node[0];
    while(ptr!=NULL){
        printf("%d\n",ptr->key);
        ptr = ptr->next;
    }
}

