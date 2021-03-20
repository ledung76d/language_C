#include<stdio.h>
int main()
{
	int a[3][3]={{2,3,4},{3,4,5},{4,5,6}};
	int i,j;
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++){
			printf(" %d ",a[i][j]);
		}
	}
}
