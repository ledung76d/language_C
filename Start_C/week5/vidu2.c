#include<stdio.h>

double thangcu(double soKwh)
{
	double thanhToan = 0;
	if (soKwh > 400)
	{
		thanhToan += (soKwh - 400) * 2701;
		soKwh = 400;
	}
	if (soKwh > 300)
	{
		thanhToan += (soKwh - 300) * 2615;
		soKwh = 300;
	}
	if (soKwh > 200)
	{
		thanhToan += (soKwh - 200) * 2340;
		soKwh = 200;
	}
	if (soKwh > 100)
	{
		thanhToan += (soKwh - 100) * 1858;
		soKwh = 100;
	}
	if (soKwh > 50)
	{
		thanhToan += soKwh * 1600;
		soKwh = 50;
	}
	if (soKwh > 0)
	{
		thanhToan += soKwh * 1549;
		soKwh = 0;
	}
	return thanhToan;
}
int main(){
	double soKwh;
	printf("Nhap vao so dien tieu thu: ");
    scanf("%d",&soKwh);
	printf("%lf",thanhcu(soKwh));
}

