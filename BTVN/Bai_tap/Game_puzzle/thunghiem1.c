#include<stdio.h>
#include<stdlib.h>

void NhapMaTran(int **a, int dong, int cot)
{
    int i, j,k;
    k=0;
    for (i = 0; i < dong; i++)
        for (j = 0; j < cot; j++)
        {
            a[i][j]=k;
            k++;
        }
}
void in_sao(int length)
{
    for(int i=0; i < length+4;i++){
        printf("*");
    }
    printf("\n");
}
void XuatMaTran(int **a, int dong, int cot)
{
    int i,j;
    in_sao(dong);
    for( i = 0; i < dong; i++){
        for ( j = 0; j < cot; j++)
        {
            printf("*%d",a[i][j]);
        }
        printf("*\n");
    }
    in_sao(dong);
}

// SWAP
void swap_right(int **a,int n){
    int i,j;
}
int main()
{
    in_sao(5);
    int **a = NULL, dong, cot;
    int i;
    printf("Nhap vao so dong = ");
    scanf("%d", &dong);
    printf("Nhap vao so cot = ");
    scanf("%d", &cot);
    // Cấp phát mảng các con trỏ cấp 1
    a = (int **)malloc(dong * sizeof(int *));
    for (i = 0; i < dong; i++)
    {
        // Cấp phát cho từng con trỏ cấp 1
        a[i] = (int *)malloc(cot * sizeof(int));
    }
    NhapMaTran(a, dong, cot);
    XuatMaTran(a, dong, cot);

    //
   
 
    // giải phóng từng hàng
    for (i = 0; i < dong; i++)
    {
        free(a[i]);
    }
    // giai phong con trỏ quản lý các dòng
    free(a);
    return 0;
}
