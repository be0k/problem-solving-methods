#include <stdio.h>
#include <stdlib.h>
struct LIST{
    char name[10];
    int age;
    char hobby[10];
};
void write(struct LIST*, int);

int main(){
    FILE *infile;
    struct LIST a[30], tmp;
    char line[100];
    int cnt = 0;

    if((infile = fopen("personal.txt","r")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    while(fscanf(infile,"%s %d %s",a[cnt].name,&a[cnt].age,a[cnt].hobby) == 3)
        cnt++;
    fclose(infile);
    write(a, cnt);
    return 0;
}


void write(struct LIST *z, int cnt){
    FILE *outfile;
    int temp = 0;
    if((outfile = fopen("output.txt","w")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    for(int r=10; r<50; r+=10){
        fprintf(outfile, "Age from %d to %d\n---------------\n", r, r+9);
        for(int i=0; i<cnt; i++){
            temp = z[i].age;
            if(r<=temp and temp<r+10)
                fprintf(outfile,"%s %d %s\n", z[i].name,z[i].age,z[i].hobby);
        }
        fprintf(outfile, "\n");
    }

    fclose(outfile);
}
