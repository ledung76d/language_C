#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char name1[9]="Mot ngay";
    int i;
    //strlen() Dem so ki tu trong xau
    printf(" %d ",strlen(name1));
    //strcpy() copy  xau cpy2 sang cpy1
    char cpy1[5]="red";
    char cpy2[5]="blue";   
    strcpy(cpy1,cpy2);
    printf("\n %s \n",cpy1);
    //strcat() noi hai chuoi voi nhau
    char cpy3[10]="Ten";
    char cpy4[10]=" la"; 
    strcat(cpy3,cpy4);
    printf("\n %s \n",cpy3);
    //strcmp() so sanh hai chuoi
    char name2[5]="C100";
    char name3[5]="C209";
    char name4[5]="C001";
    printf("\n %d %d %d\n ",
    strcmp(name2,name3),strcmp(name1,name1),strcmp(name3,name4));
    //chuyen ki tu so sang so kieu int
    char name5[5]="1102";
    int n;
    n=atoi(name5);
    printf("\n %d \n",n);
}