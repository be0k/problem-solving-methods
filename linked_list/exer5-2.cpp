#include <stdio.h>
#define search 220

struct NODE{
    int key;
    struct NODE *next;
}node[4];


int main(){
    int i;
    bool found = false;
    struct NODE *ptr;

    //linked list
    node[0].key = 100;
    node[1].key = 150;
    node[2].key = 200;
    node[3].key = 250;
    for(i=0; i<3; i++)
        node[i].next = &node[i+1];
    node[i].next = NULL;

    //find search
    ptr = &node[0];
    while(ptr->next != NULL){
        if(ptr->key == search){
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    printf(found?"search key found\n":"search key not found\n");
}
