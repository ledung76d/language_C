#include <stdio.h>

int main()
{
	double price,price10,price20,price10lamphat;
	printf("Nhap vao so tien ban muon vay: ");
	scanf("%lf",&price);
	price10=price20=price10lamphat=price;
	for(int i=0;i<10;i++)
	    {price10=price10*(1+0.12);
	     price10lamphat=price10lamphat*(1+0.08);}
	for(int i=0;i<20;i++)
	    {price20=price20*(1+0.12);}
	printf("Tong so tien phai tra neu dung ki han 10 nam : %.2lf dong\n",price10);
	printf("Tong so tien phai tra neu dung ki han 20 nam: %.2lf dong\n",price20);
	printf("------------------------------------------------------------------------------------\n");
	printf("Vay so tien chenh lech giua ky han 20 nam va ky han 10 nam la: %.2lf dong\n",price20-price10);
	printf("====================================================================================\n");
	printf("Neu ap dung ti le lam phat 4%/nam thi so tien lai phai tra lai ngan hang sau 10 nam la: %.2lfdong",price10lamphat);
	return 0;
}

