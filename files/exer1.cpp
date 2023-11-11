#include <stdio.h>
#define N 2

struct CAR{
    char name[20];
    int year;
};
int main(){
    struct CAR car[N] = {{"Avante", 2007},
                        {"Sonata", 2008}};
    FILE *infile, *outfile;
    int temp;
    char ch;
    outfile = fopen("cars.txt","w");
    if(outfile == NULL){
        printf("can not open cars.txt\n");
        return 1;
    }

    for(int i=0; i<N; i++)
        fprintf(outfile, "%s \t %d\n",car[i].name, car[i].year);
    fclose(outfile);

    infile = fopen("cars2.txt", "r");
    while((ch = fgetc(infile))!=EOF)
        printf("%c",ch);
    fclose(infile);
    return 0;
}

