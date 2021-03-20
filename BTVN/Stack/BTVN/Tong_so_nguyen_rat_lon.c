#include<stdio.h>
#include<stdlib.h>

#define MAX 50

struct stack{
    int data;
    struct stack *next;
};
typedef struct stack STACK;

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

int change( char c) // doi ki tu char sang int
{
    return (int)c-48;
}


void tinh_cong(char a[],char b[]){
    int value3;
    STACK *node1=NULL;
    int value1=0;
    for(int i=0;i<strlen(a);i++){
        value1=change(a[i]);
        node1=push(node1,value1);
    }

    STACK *node2=NULL;
    int value2=0;
    for(int i=0 ;i<strlen(b);i++)
    {
        value2=change(b[i]);
        node2=push(node2,value2);
    }

    STACK *temp=NULL;
    int result=0; // So nho de cong tong
    int length,T_short; //l
    T_short=strlen(a)-strlen(b);
    if(T_short>0) length=strlen(b);
    else{
        length=strlen(a);
        T_short=-T_short;
    }
    for (int i=0;i<length;i++){
        node1=pop(node1,&value1);
        node2=pop(node2,&value2);
        if(value1+value2>9){
            value3=value1+value2-10+result;
            temp=push(temp,value3);
            result=1;
        }else
        {
            value3=value1+value2+result;
            temp=push(temp,value3);
            result=0;
        }
    }
    
    if (T_short==0 && result==1)
    {
        temp=push(temp,1);
    }
    
         
    for(int i=0;i<T_short;i++){
        if (strlen(a)>strlen(b)){
            node1=pop(node1,&value1);
            temp=push(temp,value1);
        }else{
            node2=pop(node2,&value2);
            temp=push(temp,value2);
        }
   
    }

    for(int i=0;i<length+T_short+result;i++){
        temp=pop(temp,&value3);
        printf("%d",value3);

    }
 

}

void main(){
    char a[50],b[50];
    printf("Nhap so thu nhat: ");
    scanf("%s",a);
    printf("Nhap so thu hai : ");
    scanf("%s",b);
    tinh_cong(a,b);
}