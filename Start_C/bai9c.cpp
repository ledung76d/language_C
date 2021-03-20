#include<stdio.h>
#include<string.h>

void inTen(char *hoten)
{
	char tmp[20];
	strcat(tmp,"");
	strcat(tmp,hoten);
	strcpy(hoten,tmp);
	int i,j;
	for(i=strlen(hoten);i>0;i--)
	{
		if(hoten[i]==' ')
		{
			j=i;
			break;
		}
	}
	for(i=j;i<strlen(hoten);i++)
	{
		printf("%c",hoten[i]);
	}
}

int main()
{
	printf("Nhap ten: ");
	char hoten[20];
	gets(hoten);
	inTen(hoten);
}
