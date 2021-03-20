#include<stdio.h>
int main (){
	//tim so lon nhat trong 2 so
	printf("Nhap lan luot 2 so ");
	int i,j;
	scanf("%d %d",&i,&j);
	if(i>j){
		printf("Max = %d",i);
	}else{
		printf("Max = %d",j);
	}
	//tim so lon nhat trong 3 so
	printf("\nNhap lan luot 3 so ");
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c){
		printf("Max = %d",a);
	}else if(b>a&&b>c){
		printf("Max = %d",b);
	}else{
		printf("Max = %d",c);
	}
	 	
	
}
