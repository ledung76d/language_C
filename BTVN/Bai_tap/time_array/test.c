#include<stdio.h>
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main()
{
    int a=1,b=10;
    swap(&a,&b);
    printf("%d %d ",a,b);

}