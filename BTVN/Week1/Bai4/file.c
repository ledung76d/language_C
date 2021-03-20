#include<stdio.h>
#include <stdlib.h>
#include<process.h>

int main() {
   FILE *fp1, *fp2;
   char a;
 
   fp1 = fopen("fileauth.txt", "r");
   if (fp1 == NULL) {
      puts("Khong the mo file nay");

   }
 
   fp2 = fopen("filefake.txt", "w");
   if (fp2 == NULL) {
      puts("Khong the mo file nay");
      fclose(fp1);

   }


   do {
      a = fgetc(fp1);
      fputc(a, fp2);
   } while (a != EOF);
 
   return(0);
}