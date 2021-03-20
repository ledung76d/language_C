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