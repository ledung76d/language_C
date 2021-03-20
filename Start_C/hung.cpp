
#include<stdio.h>
#include<conio.h>
#define max_cot 100
#define max_hang 100

int main()
{ 
    int a[50][50];
    int i,j,m,n;
    printf("nhap so hang n="); scanf("%d",&n);
    printf("nhap so cot m="); scanf("%d",&m);
    printf("nhap vao ma tran:\n");
    for(i=0;i<n;i++)
    {
    	printf("Nhap vao hang thu %d: ",i+1);
        for(j=0;j<m;j++)
        {
        	
            scanf("%d",&a[i][j]);
        }
    }
    printf("ma tran vua nhap la:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
