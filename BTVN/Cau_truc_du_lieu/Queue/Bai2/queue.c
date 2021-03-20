#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next; //pointer to next element
};
typedef struct Node Node;
typedef struct Node *Position;
typedef struct
{
    Position Front, Rear; // Con tro dau va con tro cuoi queue 
} Queue;

//Khoi tao mot hang doi trong 
void MakeNullQueue(Queue *Q)
{
    Position Header;
    Header = (Node *)malloc(sizeof(Node));
    //Allocation Header
    Header->Next = NULL;
    Q->Front = Header;
    Q->Rear = Header;
}
//Kiem tra Queue co rong khong 
int EmptyQueue(Queue Q)
{
    return (Q.Front == Q.Rear);
}
// Thêm phan tu vào cuoi(rear) của Queue.
void EnQueue(ElementType X, Queue *Q)
{
    Q->Rear->Next =(Node *)malloc(sizeof(Node));
    Q->Rear = Q->Rear->Next;
    Q->Rear->Element = X;
    Q->Rear->Next = NULL;
}
// Xoa phan tu dau khoi(front) của Queue. Neu Queue rong thi bao error.
/*
void DeQueue(Queue *Q)
{
    if (!Empty_Queue(Q))
    {
        Position T; 
        T = Q->Front;
        Q->Front = Q->Front->Next;
        free(T);
    }
    else
        printf("Error: Queue is empty.");
}
*/
int main(){
    Queue * q;
    MakeNullQueue(q);
    EnQueue(2,q);

    printf("Queue front : %d",q->Front->Element);


   
}