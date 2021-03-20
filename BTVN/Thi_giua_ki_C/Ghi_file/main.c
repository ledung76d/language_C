#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void Showmenu(){
    FILE *fp;
  
    fp=fopen("vanban.txt","w");
    if(fp==NULL){
        printf("<Error file>");
       exit(1);
    }
    int count=0;
    char c[6];
    //Nhap du lieu vo file
    char sentence[1000];
    printf("Entera sentence:\n");
    while(1){
        printf("Name: ");
        gets(sentence);
        //clearBuffer();
        if(strcmp(sentence, "===")==0) break;
        fprintf(fp,"%s   ",sentence);
        printf("Tien: ");
        gets(sentence);
        //clearBuffer();
        fprintf(fp,"%s   \n",sentence);

    }
       
    printf("Kq: %d",count);
    fclose(fp);
}

int main(){
    Showmenu();
    return 0;
}