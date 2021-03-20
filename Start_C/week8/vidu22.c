#include <stdio.h>
#include <string.h>
int main() {
	char hoten[100],tmp[100];
	gets(hoten);
	strcat(tmp," ");
	strcat(tmp,hoten);
	strcpy(hoten,tmp);
	int i = strlen(hoten)-2;
	while (hoten[i]!=' ') i--;
	while (hoten[i]!='\0') {
		printf("%c",hoten[i]);
		i++;
	}
	return 0;
}
