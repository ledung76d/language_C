#include <stdio.h>
#define MAX 100

void NhapMaTran(int a[][MAX], int m, int n)
{
	int i,j;
    for( i = 0; i < n; i++)
    	for(j = 0; j < m; j++)
    	{
    		do
			{
        	printf("A[%d][%d] = ", i, j);
        	scanf("%d", &a[i][j]);
        	if (a[i][j]<0) 
        		printf("Cac phan tu trong ma tran khong am. \nXin moi nhap lai!\n");
        	}while(a[i][j]<0); // kiem tra phan tu nhap co thoa man khong am ko
    	}
    	printf("\n");
}
 
void XuatMaTran(int a[][MAX], int m, int n)
{
	int i,j;
    for(i = 0; i < n; i++)
    {
		for(j = 0; j < m; j++)
		printf("%d\t", a[i][j]);
      	printf("\n");
    }
}

void TB_cot_chan(int a[][MAX],int m,int n)
 {
	int i,j;
 	int sum=0, max,dem=0;
    for(j = 0; j < m; j++)
    {	
    	max=0;
    	if(j%2!=0) // kien tra dieu dien xem co o cot chan ko
    	{
			for(i = 0; i < n; i++)
			{
				if(a[i][j]>max) max=a[i][j];
			}
			dem++; // dem so cot chan
			sum=sum+max; //tinh tong cac so max
		}
    }
	float trungBinh;
	trungBinh=(1.0*sum)/dem; // tinh trung binh cong
	printf("\nTrung binh cong cua cac gia tri lon nhat tren cot chan %.2lf ",trungBinh);  
    
 } 
 
 void tongPhan_tu(int a[][MAX],int m,int n)
 {
 	int i,j,isum=0;
 	for (i = 0; i <n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if((2<=a[i][j] && a[i][j]<=20 && a[i][j]%3==0)) // kiem tra dk thuoc[0,20] va chia het cho 3
			{
				isum=isum+a[i][j];
			}
        }
    };
   	printf("\nTong cac phan tu thuoc[0,20] va chia het cho 3 %d",isum);
}

 
int main(){
    int a[MAX][MAX];
    int m,n;
    printf("nhap so hang n = "); 
	scanf("%d",&n);
    printf("nhap so cot m = "); 
	scanf("%d",&m);
    printf("nhap vao ma tran:\n");
    NhapMaTran(a, m , n);
    XuatMaTran(a, m, n);
    TB_cot_chan(a, m, n);
    tongPhan_tu(a, m, n);
}
