#include"stack.h"

int main(){
    STACK *temp=NULL;
    int value;
    printf("Nhap so: ");
    scanf("%d",&value);
    temp=push(temp,value);
    value=0;
    temp=pop(temp,&value);
    printf("==  %d  == ",value);
}