#include <stdio.h>
#include <string.h>

void inTen(char *hoten)// char hoten[50]
{
	char tmp[5];
	strcat(tmp," ");
	strcat(tmp,hoten);
	strcpy(hoten,tmp);
	
	int i=strlen(hoten)-2;
	while (hoten[i]!=' ') i--;
	printf("Ten: ");
	while (hoten[i]!='\0') {
		printf("%c",hoten[i]);
		i++;
	}
}

int main() {
	char hoten[100];
	printf("Nhap ho ten");
	gets(hoten);
	inTen(hoten);
	return 0;
}
