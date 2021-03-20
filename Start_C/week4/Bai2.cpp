//Tinh so tien chenh lech giua 2 ki han
#include<stdio.h>

int main() {
	//Nhap du lieu
    float rate3,rate6,tien,tienlai1,tienlai2,nam2,nam5;
    printf("Nhap so tien gui:");
    scanf("%f",&tien);
	rate3=4.70/4/100;
	rate6=5.10/2/100; 
    
    //Tien lai chenh lech sau 2 nam 
	tienlai1=tien;
    tienlai2=tien; 	
	for(int i=1;i<=8;i++){
		tienlai1=tienlai1*(1+rate3);
	}
	for(int i=1;i<=4;i++){
		tienlai2=tienlai2*(1+rate6);
	}
	nam2=tienlai2-tienlai1;
	printf("\nSo tien chenh lech cuoi cung sau 2 nam = %.2f ",nam2);
	//Tien lai chenh lech sau 5 nam
	tienlai1=tien;
    tienlai2=tien;
	for(int i=1;i<=20;i++){
		tienlai1=tienlai1*(1+rate3);
	}
	for(int i=1;i<=10;i++){
		tienlai2=tienlai2*(1+rate6);
	}
	nam5=tienlai2-tienlai1;
	printf("\nSo tien chenh lech cuoi cung sau 5 nam = %.2f ",nam5);
    return 0;
}

