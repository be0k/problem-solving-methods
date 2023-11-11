#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIST{
    char name[10];
    int age;
    char hobby[10];
};
void swap(struct LIST*, struct LIST*);
void sort(struct LIST*, int, bool);
void write(struct LIST*, int, bool);

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
    write(a, cnt, true);
    write(a, cnt, false);
    return 0;
}

void swap(struct LIST *x, struct LIST *y){
  struct LIST temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


void sort(struct LIST *z, int cnt, bool type){
  for(int i=0; i<cnt-1; i++){
    for(int j=0; j<cnt-1-i; j++){
      if(type ? z[j].age > z[j+1].age : strcmp(z[j].hobby, z[j+1].hobby) > 0){
        swap(&z[j], &z[j+1]);
      }
    }
  }
}
void write(struct LIST *z, int cnt, bool type){
    FILE *outfile;
    sort(z, cnt, type);
    if((outfile = fopen(type ? "age.txt" : "hobby.txt", "w")) == NULL){
        printf("File Could Not Be Opened.\n");
        exit(1);
    }
    for(int i=0; i<cnt; i++)
      fprintf(outfile, "%s %d %s\n", z[i].name, z[i].age, z[i].hobby);

    fclose(outfile);
}
