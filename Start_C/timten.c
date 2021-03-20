#include<stdio.h>
#include<string.h>
char* timten(const char hoten[]);

int main()
{
	char hoten[80];
	
	printf("Nhap mot xau ho va ten:");
	gets(hoten);
	printf("Ten sau khi tach duoc: %s",timten(hoten));
	return 0;
}



char* timten(const char hoten[])
{
	int i;
	i=strlen(hoten)-1;
	while(i>=0 && hoten[i] !=' ') i--;
	return hoten+i+1;
}

