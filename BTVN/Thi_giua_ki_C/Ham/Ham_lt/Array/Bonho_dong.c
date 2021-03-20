#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int n;
    printf("N= ");
    scanf("%d",&n);
    //mang dong 1 chieu
    int *b;
    b=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        b[i]=i;
    }
    printf("Kq= ");
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    
    //mang dong 2 chieu
    int **a = NULL;
    // Cấp phát mảng các con trỏ cấp 1
    a = (int **)malloc(n * sizeof(int *)); //n so thu tu hang
    for (int i = 0; i < n; i++)
    {
        // Cấp phát cho từng con trỏ cấp 1
        a[i] = (int *)malloc(n * sizeof(int)); //n so thu tu cot
    }
}