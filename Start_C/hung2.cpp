#include<stdio.h>
 
int main ()
{
	int a,b;
	do
	{
		printf("Nhap lan luot 2 so a,b");
		scanf("%d%d",&a,&b);
		if(a<0||b<0) printf("Hay nhap lai gia tri a va b")
	}while(a<0||b<0);
	if(a>b) printf("a lon hon b");
	else printf("b lon hon a");
}
