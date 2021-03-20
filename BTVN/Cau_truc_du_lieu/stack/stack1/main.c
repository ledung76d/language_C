#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node STACK;

STACK *push(STACK *p, int value) // them phan tu vao dau stack
{
    STACK *temp;
    temp=(STACK *)malloc(sizeof(STACK));
    if(temp==NULL){
        printf("Memory available Error\n");
        exit(0);
    }
    temp->data=value;
    temp->next=p;
    p=temp;
    return (p);
}

STACK *pop(STACK *p, int *value) //lay ra phan tu tren dinh stack
{
    STACK *temp;
    if(p==NULL){
        printf(" The stack is empty can not pop Error\n");
        exit(0);
    }
    *value=p->data;
    temp=p;
    p=p->next;
    free(temp);
    return p;

}
void main(){
    STACK *top=NULL;
    int n,value;
    do{
        do{
            printf("Enter the element to be pushed\n");
            scanf("%d",&value);
            top=push(top,value);
            printf("Enter 1 to continue\n");
            scanf("%d",&n);
        }while(n==1);
        printf("Enter 1 to pop an element\n");
        scanf("%d",&n);
        while (n==1)
        {
            top=pop(top,&value);
            printf("THe value poped is %d\n",value);
            printf("Enter 1 to pop an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 to continue\n");
        scanf("%d",&n);
    }while(n==1);
}