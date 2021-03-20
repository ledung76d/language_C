#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int ElementType;
struct _PointerType
{
    ElementType Inf;
    struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

PointerType *InsertMiddle(PointerType *Prev,ElementType X){
    PointerType *TempNode;

    TempNode=(PointerType *)malloc (sizeof(PointerType));
    TempNode->Inf=X;
    TempNode->Next =Prev->Next;
    Prev->Next=TempNode;

    return TempNode;
}

ElementType Delete(PointerType *Prev){
    ElementType X;
    PointerType *TempNode;


}