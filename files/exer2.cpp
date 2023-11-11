#include <stdio.h>
#define N 4
struct CAR{
    char name[20];
    int year;
    double price;
};
int main(){
    struct CAR car[N] = {{"Avante", 2007, 13000.00},
                        {"Sonata", 2008, 18000.00},
                        {"SM7", 2009, 22000.00},
                        {"Equus", 2010, 35000.00}};
    FILE *infile, *outfile;
    int temp;
    char ch;
    outfile = fopen("cars2.txt","w");
    if(outfile == NULL){
        printf("can not open cars2.txt\n");
        return 1;
    }
    fprintf(outfile,"----------------------------\n");
    fprintf(outfile, "|Name \t |Year \t |Price    |\n");
    fprintf(outfile,"----------------------------\n");
    for(int i=0; i<N; i++)
        fprintf(outfile, "|%-7s | %-6d| %-5.2lf|\n",car[i].name, car[i].year, car[i].price);
    fprintf(outfile,"----------------------------\n");
    fclose(outfile);
    infile = fopen("cars2.txt", "r");
    while((ch = fgetc(infile))!=EOF)
        printf("%c",ch);
    fclose(infile);
    return 0;
}
