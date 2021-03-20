#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int sosanh(int a[], int b[])
{
    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}
//

int main()
{
    int a[MAX], b[MAX];
    int i, n, m;

    printf("So phan tu mang 1 :");
    scanf("%d", &n);
    printf("\nNhap mang thu nhat: \n");
    for (i = 0; i < MAX; i++)
    {
        if(i<n){
            scanf("%d", &a[i]);
        }
        else a[i]=0;
        
    }

    printf("So phan tu mang 2:");
    scanf("%d", &m);
    printf("\nNhap mang thu hai: \n");
    for (i = 0; i < MAX; i++)
    {
        if(i<m){
            scanf("%d", &b[i]);
        }
        else b[i]=0;
        
    }

    printf("Kq: %d", sosanh(a, b));
}