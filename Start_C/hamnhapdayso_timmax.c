#include<stdio.h>

int nhapSo(int a[])
{
	int n;
	printf("\nSo phan tu day so: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) {
		printf("\nNhap phan tu thu %d ",i+1);
		scanf("%d",&a[i]);
	} 
}

int timMax(int a[] ,int n)
{
	int max,tmp,i,j;
	max=tmp=a[0];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("\nMax = %d",a[0]);
	printf("\nMin = %d",a[n-1]);
}

int main()
{
	int a[100],b[100],c;
	printf("\nDay so thu 1");
	nhapSo(a);
	c=sizeof(a);
	timMax(a,c);
	printf("\nDay so thu 2");
	nhapSo(b);
	
}
