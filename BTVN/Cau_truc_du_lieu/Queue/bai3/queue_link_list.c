#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;    
};
typedef struct node NODE;
//Khai bao cau truc queue
struct queue
{
    NODE *Front; // con tro dau
    NODE *Rear; //con tro cuoi
};
typedef struct queue QUEUE;

//khoi tao queue rong
void KhoiTaoQueue(QUEUE *q){
    q->Front=NULL;
    q->Rear=NULL;
}

//Khoi tao 1 cai node
NODE * KhoiTaoNode(int x){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL){
        printf("No memory available Error\n");
        exit(0);
    }
    p->data = x; // them gia tri cua x vao trong data cai node
    p->next=NULL;
    return p;
}
//Kiem tra Queue rong khong
int IsEmpty(QUEUE *q){ 
    if(q->Front==NULL) return 1 ;
    return 0;
}
//===========Them 1 phan tu vao cuoi queue==========
void Push(QUEUE *q ,NODE *p)
{
    if(p==NULL) return 1;
    //Neu danh sach rong
    if(IsEmpty(q)==1){
        q->Front=q->Rear=p; //node p chinh la node dau va node cuoi
    }
    else {
        q->Rear->next=p;
        q->Rear=p;
    }
}

//=================Lay han tu dau Que va huy no di========================
void Pop(QUEUE *q, int *value){
    if (IsEmpty(q)==1){
        return 1;
    }
    else{
        NODE *temp=q->Front;
        value=temp->data;
        q->Front=q->Front->next;
        free(q);
    }
}
// xem thong tin phan tu dau


int main(){
    QUEUE *qq;
    KhoiTaoQueue(qq);
    int x;
    printf("Nhap gia tri: ");
    scanf("%d",&x);
    NODE *pq=KhoiTaoNode(x);
    Push(qq,pq);
    Push(qq,pq);

    int value;
    Pop(qq,&value);
    printf("%d",value);


}