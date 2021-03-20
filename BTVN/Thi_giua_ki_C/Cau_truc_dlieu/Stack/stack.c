#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist STACK;
//them phan tu vao dau stack
STACK *push( STACK * b,int value); 

//lay ra phan tu tren dau stack
STACK *pop(STACK *p, int *value);

//Them phan tu vao dau stack
STACK *push( STACK * p,int value){
    STACK *temp;
    temp=(STACK *)malloc(sizeof(STACK));
    if(temp==NULL){
        printf("No memory available Error\n");
        exit(0);
    }
    temp->data=value;
    temp->next=p;
    p=temp;
    return p;
}
//lay phan tu top trong stack
STACK *pop(STACK *p, int *value){
    STACK *temp;
    if(p==NULL){
        printf("The stack is empty can not pop Error\n");
        exit(0);
    }
    *value=p->data;
    temp=p;
    p=p->next;
    free(temp);
    return p;
}
int IsEmpty(STACK *p){
    if(p==NULL){
        return 1;
    }
    return 0;
}
int main(){
    STACK *top=NULL;
    printf("%d\n",IsEmpty(top));
    //Them phan tu vao stack
    top=push(top,1);
    //Lay phan tu ra stack
    int value=0;

    top=pop(top,&value);
    printf("Kq= %d",value);
    free(top);

}