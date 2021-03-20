#include <stdio.h>
#include<string.h>
char * timten(const char hoten[]);
void xoa_dau_cach(char *str);
void hovaten(const char hoten[],char *ho,char *ten);

int main()
{
	char hoten[80];
	char ten[40];
	char ho[40];
	printf("Nhap mot xau ho va ten: ");
	xoa_dau_cach(hoten);
	gets(hoten);
	printf("Ten sau khi tach duoc: %s", timten(hoten));	
	hovaten(hoten,ho,ten);
	printf("\nTen sau khi chia tach duoc:%s va %s",ho,ten);
}

char * timten(const char hoten[])
{
	int i;
	i=strlen(hoten)-1;
	/* tim ki tu trang cuoi cung trong xau*/
	while(i>0 && hoten[i]!= ' ') i--;
	return hoten + i + 1;
}
void xoa_dau_cach(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
		if(str[i]==' '&&str[i+1]==' '){
			strcpy(str + i,str + i + 1);
			i--;
		}
	if(str[0]==' ') strcpy(str,str+1);
	if(str[strlen(str)-1]==' ')
		str[strlen(str)-1]= '\0';
}
void hovaten(const char hoten[],char *ho,char *ten)
{
	int i;
	i=strlen(hoten)-1;
	while(i>=0 &&hoten[i]!=' ') i--;
	strncpy(ten,hoten+i+1,strlen(hoten)-i);
	strncpy(ho,hoten,i);
	ho[i]='\0';
}
