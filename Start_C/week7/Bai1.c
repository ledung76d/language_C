#include <stdio.h>
#include <math.h>
#include <string.h>

const int max=100;
int main() {
   char hoten[max][15];
   int i,j,traloi=0,n=0;
   for(i=0;i<max;i++)
   do{
   		printf("Nhap ho ten thu %d: ",n+1);
        fflush(stdin);
	    gets(hoten[i]);
	    printf("Nhap tiep nhan 1: ko nhap nua nhan 0 ");
	    scanf("%d",&traloi);
	    n++;
	    if(traloi==0) break;
   }while(n>0);
   
   // sap xep
	char ten[20];
	for ( i= n; i > 0; --i)
	{
		for ( j = 0; j < i; ++j)
		{
			if (strcmp(hoten[j], hoten[j + 1]) == 1)
			{

				strcpy(ten, hoten[j]);
				strcpy(hoten[j], hoten[j + 1]);
				strcpy(hoten[j + 1], ten);
			}
		}
	}
	
	// in danh sch sau sx
	printf("Danh sach sau sx:");
	for ( i = 0; i <= n; i++)
	{
		printf("%s \n", hoten[i]);
	}
}
