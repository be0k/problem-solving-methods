#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int main(){
    int slot[N];
    int i;
    char enter = '\n';
    int cherry = 0;
    int same = 0;
    char out[4][10] = {"BAR","BELL","LEMON","CHERRY"};
    char fst[3][10] = {"First","Second","Third"};

    //set_seed
    srand(time(NULL));
    
    //print_base
    printf("\ncelcom to KW Land\nPlease pull the slot machine !!\n\n");
    
    while(enter == '\n'){
        //setting
        cherry = 0;

        for(i=0; i<N; i++){
            slot[i] = (rand()%4)+1;
            printf("%s is %s\n", fst[i],out[slot[i]-1]);
            if(slot[i] == 4){
                cherry++;
            }
        }

        if (cherry == 3){
            printf("\nPaid out : Jacpot");
        }
        else if(cherry >= 1){
            printf("\nPaid out : One Dime");
        }
        else if(slot[0]==slot[1] and slot[1] == slot[2]){
            printf("\nPaid out : One Nickel");
        }
        else{
            printf("\nSorry. Better Luck Next Time");
        }
        printf("\nPress Enter key to continue\n\n");
        scanf("%c", &enter);
    }
    return 0;
}