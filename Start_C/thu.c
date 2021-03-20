#include<stdio.h>

int nhapso()
{
	int n;
	printf("Nhap so: ");
	scanf("%d",&n);
	return n;
}

int max(int a ,int b)
{
	return a>b?a:b;
}

int main()
{
	int a,b,c,d;
	a=nhapso();
	b=nhapso();
	c=nhapso();
	d=max(b,c);
	printf("Gia tri lon nhat = %d",max(a,max(b,c)));
}
