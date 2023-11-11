#include <stdio.h>
#include <stdlib.h>
struct LIST{
    char name[10];
    int age;
    float salary;
};

int read(struct LIST *arr, char *);
void write(struct LIST*, int, int, float, char *);

int main(){
    FILE *infile;
    struct LIST a[30], b[30];
    char f_1[100]="salary_v1.txt";
    char f_2[100]="salary_v2.txt";
    char f_3[100]="salary_v3.txt";
    int cnt, b_cnt;

    cnt = read(a, f_1);
    write(a, cnt, 40, 1.1, f_2);
    cnt = read(a, f_2);
    write(a, cnt, 30, 1.2, f_3);
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


void write(struct LIST *z, int cnt, int range, float rate, char *file_name){
    FILE *outfile;
    int temp = 0;
    if((outfile = fopen(file_name,"w")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    
    for(int i=0; i<cnt; i++){
        temp = z[i].age;
        if(range<=temp && temp<range+10)
            fprintf(outfile,"%-6s %3d %8.1f\n", z[i].name,z[i].age,(z[i].salary)*rate);
        else
            fprintf(outfile,"%-6s %3d %8.1f\n", z[i].name,z[i].age,(z[i].salary));
    }
    fclose(outfile);
}
