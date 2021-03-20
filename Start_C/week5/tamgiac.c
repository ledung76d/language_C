#include<stdio.h>

int main ()
{
	int n,i,j;
	printf("nhap chieu cao tam giac:");
	scanf("%d",&n);
	//tam giac can
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		printf(" ");
		for(j=1;j<=2*i-1;j++)
		printf("*");
		printf("\n");
	}
	//tam giac vuong trai
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		printf(" ");
		for(j=1;j<=i;j++)
		printf("*");
		printf("\n");
	}
	//tam giac vuong phai
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++) printf("*");
		printf("\n");
	}
	//tam giac vuong can
	for(i=1;i<=n;i++){
		for(j)
	}
}
