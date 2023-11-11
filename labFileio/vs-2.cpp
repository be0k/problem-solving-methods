#include <stdio.h>
#include <stdlib.h>
struct LIST{
    char name[10];
    int age;
    float salary;
};

int read(struct LIST *arr, char *);
void write(struct LIST*, int, int, float, char *);
void compare(struct LIST *, struct LIST *, int);

int main(){
    FILE *infile;
    struct LIST a[30], b[30];
    char f_1[100]="salary_v1.txt";
    char f_2[100]="salary_v2.txt";
    char f_3[100]="salary_v3.txt";
    int cnt, b_cnt;

    cnt = read(a, f_1);
    b_cnt = read(b, f_3);
    if(cnt != b_cnt){
        printf("The number of %s and %s is not match.\n", f_1, f_3);
        exit(1);
    }
    compare(a, b, cnt);
    return 0;
}


int read(struct LIST *arr, char *file_name){
    FILE *infile;
    int cnt = 0;
    if((infile = fopen(file_name,"r")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    while(fscanf(infile,"%s %d %f",arr[cnt].name, &arr[cnt].age, &arr[cnt].salary) == 3)
        cnt++;
    fclose(infile);
    return cnt;
}


void compare(struct LIST *x, struct LIST *y, int cnt){
    for(int i=0; i<cnt; i++){
        printf("%-6s %3d %8.1f --> %8.1f\n", x[i].name, x[i].age, x[i].salary, y[i].salary);
    }
}
