#include <stdio.h>
#include <stdlib.h>
#define N 3

struct NODE{
    int key;
    struct NODE *next;
}node[N];

struct NODE* insert(struct NODE *ll, int val);
void del(struct NODE *ll, int val);

int main(){
    int i, i_key = 50, d_key=100;
    struct NODE *new_ll, *ptr;

    //linked list
    node[0].key = 100;
    node[1].key = 250;
    node[2].key = 467;

    for(i=0; i<N-1; i++)
        node[i].next = &node[i+1];
    node[i].next = NULL;

    new_ll = insert(node, i_key);
    del(new_ll, d_key);
    ptr = new_ll;
    while(ptr!=NULL){
        printf("%d\n",ptr->key);
        ptr = ptr->next;
    }
    free(new_ll);
}

struct NODE* insert(struct NODE *ll, int val){
    struct NODE *first, *ptr, *old_ptr=NULL;
    int fail=-1;
    first = (struct NODE *)malloc(sizeof(struct NODE));
    ptr=&ll[0];

    if(first == NULL){
        printf("memory allocation fail.\n");
        exit(1);
    }

    first->key = val;
    first->next = NULL;

    if(first->key < ptr->key){
        first->next = ptr;
        printf("key inserted in first\n");
        return first;
    }
    while(ptr != NULL){
        if(ptr->key == first->key){
            printf("key already exists\n");
            fail=0;
            break;
        }
        if(ptr->key < first->key){
                old_ptr = ptr;
                ptr = ptr-> next;

        }
        else{
            old_ptr->next = first;
            first->next = ptr;
            fail=0;
            printf("key inserted in middle\n");
            break;
        }
    }
    if(fail){
        first->next = NULL;
        old_ptr->next = first;
        printf("key inserted in last\n");
    }
    return ll;
}

void del(struct NODE *ll, int val){
    int deleted=0;
    struct NODE *ptr, *old_ptr=NULL;

    ptr = &ll[0];
    while(ptr != NULL){
        if(ptr->key == val){
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


