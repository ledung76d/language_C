#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int sosanh(int a[],int n, int b[],int m)
{
    int i=0;
    for(i=0; i<MAX; i++)
    {
        if( n!=m)
            return 0;
        else if(a[i]!=b[i])
            return 0;
    }
    return 1;

}
//

int main()
{
    int i,n,m;

    printf("So phan tu mang 1 :");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("\nNhap mang thu nhat: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("So phan tu mang 2:");
    scanf("%d",&m);
    int *b=(int *)malloc(m*sizeof(int));
    printf("\nNhap mang thu hai: \n");
    for(i=0; i<m; i++)
    {
        scanf("%d",&b[i]);
    }

    printf("Kq: %d",sosanh( a,n,b,m));


}