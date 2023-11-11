#include <stdio.h>
#include <stdlib.h>
struct LIST{
    char name[10];
    int age;
    char hobby[20];
};

int read(struct LIST *arr, char *);

int main(){
    FILE *infile;
    struct LIST a[30];
    char f_1[100]="personal.txt";
    char f_2[100]="age.txt";
    char f_3[100]="hobby.txt";
    int cnt;

    cnt = read(a, f_1);
    FILE *outfile;
    int temp = 0;
    if((outfile = fopen(f_2,"w")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    for(int i=0; i<cnt; i++){
        fprintf(outfile,"%-6s %-3d\n", a[i].name, a[i].age);
    }
    fclose(outfile);

    if((outfile = fopen(f_3,"w")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    for(int i=0; i<cnt; i++){
        fprintf(outfile,"%-6s %-10s\n", a[i].name, a[i].hobby);
    }
    fclose(outfile);

    return 0;
}


int read(struct LIST *arr, char *file_name){
    FILE *infile;
    int cnt = 0;
    if((infile = fopen(file_name,"r")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    while(fscanf(infile,"%s %d %s",arr[cnt].name, &arr[cnt].age, arr[cnt].hobby) == 3)
        cnt++;
    fclose(infile);
    return cnt;
}
