#include<stdio.h>
int main(){
	int a,i,b,n;
	printf("Nhap n = ");
    scanf("%d", &n);
	a = n+1;  
	while(1) {
	    b = 1;
	    for (i = 2; i < a; i++) 
	    	 if (a%i==0) {
				 b = 0; 
				 break;
		 	}
	    if (b) {
			printf("So nguyen to dau tien lon hon n: %d", a);  
			break;
		}
	    a++;
	}

}
