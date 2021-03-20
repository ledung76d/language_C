#include<stdio.h>
#include<string.h>
const int max=4;
int main() {
   char hoten[max][15];
   int i,j;
   for(i=0;i<4;i++)
   {
       printf("Nhap ho ten: ");
       gets(hoten[i]);
	   fflush(stdin);
   }
   // sx danh sach
   
   for(i=0;i<max;i++){
   		for(j=i+1;j<max;j++){
   			if(strcmp(hoten[i],hoten[j])<0)
   			char ten[20];
   			strcpy(ten,hoten[i]);
   			strcpy(hoten[i],hoten[j]);
   			strcpy(hoten[j],ten);
		   }
   }
   
   // danh sach sau sx
   printf("Cac ten vua nhap\n");
   for(i=0;i<max;i++)
   printf("%s\n",hoten[i]);
   
   return 0;
}

