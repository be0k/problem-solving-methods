#include <stdio.h>

// int main(){
//     FILE *infile;
//     char line[100];
//     int lcount = 0;

//     if((infile = fopen("charstream.txt","r")) == NULL){
//         printf("File Could Not Be Opened\n");
//         return 1;
//     }

//     while (fgets(line, sizeof(line), infile) != 0){
//         lcount ++;
//         printf("Line %d : %s", lcount, line);
//     }
//   return 0;
// }




// int main(){
//     int i;
//     FILE * myFile;
//     char ch;
//     myFile = fopen("myinFile.txt", "r");

//     if(myFile==NULL)
//         printf("\nFile Could Not Be Opened");
//     else{
//         ch = fgetc(myFile);
//         while(ch != EOF){
//             putchar(ch);
//             ch =fgetc(myFile);
//         }
//         printf("\nFinished printing the file \n");
//         fclose(myFile);
//     }
//  return 0;
// }



// int main(){
//     FILE * myFile;
//     char ch;

//     myFile = fopen("data.txt", "r");
//     if (myFile==NULL){
//         printf("Could not open data.txt!\n");
//         return 1;
//     }

//     while((ch=fgetc(myFile)) != EOF)
//         putchar(ch);
//     fclose(myFile);
//     return 0;
// }



// int main(){
//     FILE *myInFile, *myOutFile;
//     char ch;

//     myInFile = fopen("data.txt","r");
//     if (myInFile==NULL){
//         printf("Could not open data.txt!\n");
//         return 1;
//     }
//     myOutFile = fopen("samedata.txt","w");
//     if (myOutFile == NULL){
//         printf("Could not open samedata.txt!\n");
//         return 1;
//     }

//     while((ch=fgetc(myInFile)) != EOF)
//         fputc(ch, myOutFile);

//     fclose(myInFile);
//     fclose(myOutFile);
// }



