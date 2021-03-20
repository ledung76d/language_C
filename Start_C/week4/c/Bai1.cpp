#include<stdio.h>

int main() {
	//Nhap du lieu
    double tienvay,laisuat,tientragop1,tientragop2,chenhlech;
    printf("Nhap vao so tien vay: ");
    scanf("%lf",&tienvay);
    //Ko co lam phat
	//Tinh tien tra  10 nam
	double a=1;
	for(int i=1;i<=10;i++)
		a=a*(1+0.12);
	tientragop1=(tienvay*a*0.12)/(a-1);//so tien tra moi nam trong 10nam
	printf("\nTong so tien phai tra trong 10 nam %.2lf dong\n",10*tientragop1);
	//Tinh tien tra  20 nam
	double b=1;
	for(int i=1;i<=20;i++)	
		b=b*(1+0.12);
	tientragop2=(tienvay*b*0.12)/(b-1);
	printf("Tong so tien phai tra trong 20 nam %.2lf dong\n",20*tientragop2);
	printf("-----------------------------------------------------------------------\n");
	chenhlech=20*tientragop2-10*tientragop1;
	printf("So tien chech lech giua hai ki han 20 nam va 10 nam: %.2lf dong\n",chenhlech);
	
	
	printf("=======================================================================\n");
	//Co lam phat
	//Tinh tien tra 20 nam
	printf("Khi co lam phat 4 pham tram\n");
 	a=1;
	for(int i=1;i<=10;i++)
		a=a*(1+0.08);
	tientragop1=(tienvay*a*0.08)/(a-1);//so tien tra moi nam trong 10nam
	printf("Tong so tien phai tra trong 10 nam %.2lf dong\n",10*tientragop1);
	//Tinh tien tra  20 nam
	b=1;
	for(int i=1;i<=20;i++)	
		b=b*(1+0.08);
	tientragop2=(tienvay*b*0.08)/(b-1);
	printf("Tong so tien phai tra trong 20 nam %.2lf dong\n",20*tientragop2);
	printf("-----------------------------------------------------------------------\n");
	chenhlech=20*tientragop2-10*tientragop1;
	printf("So tien chech lech giua hoi ki han 20 nam va 10 nam khi co lam phat: %.2lf dong",chenhlech);
    return 0;
}

