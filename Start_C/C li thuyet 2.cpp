#include<stdio.h>
int main (){
	// Tinh toan
	printf("Tinh phuong trinh ax+b=0\n");
	printf("Hay nhap a va b :");
	int a,b;
	scanf("%d %d",&a,&b);
	switch (a){
		case 0:
			if(b==0){
			printf("Phuong trinh co vo so nghiem ");
		}else{ 
			printf("Phuong trinh vo nghiem");
		}
			break;
		default:
			printf("Phuong trinh co nghiem x = %f ",(float)-b/a);
	}
	
	 	
	
}
