#include <stdio.h>
#include<string.h>
void sxGiamdan(int a[]);

int main()
{
	int a[10]={1,9,8,43,5,2,5,12,18,23};
	sxGiamdan(a);	
}


void sxGiamdan(int a[])
{
	int i,j,tmp=0;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(a[i]<a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("In day so: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
} 

