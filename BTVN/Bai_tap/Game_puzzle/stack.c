#include"stack.h"

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