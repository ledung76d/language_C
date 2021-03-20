#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int  main(){
    printf("%d",strcmp("0","0"));
    int option=1;
    char g[10]="0";
    char name[10];
    int n=0;
    do{
        printf("Name of directory: ");
        scanf("%s",name);
        n++;
    }while(strcmp(name,"0")!=0);
    
}