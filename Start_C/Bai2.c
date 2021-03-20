#include<stdio.h>

int main()
{
	double usdvnd = 0, eurusd = 0;
	printf("Nhap ti gia USDVND va EURUSD: ");
	scanf("%lf%lf", &usdvnd,&eurusd);
	
	double tienvnd = 0;
	printf("Nhap so tien Vnd can phai doi: ");
	scanf("%lf", &tienvnd);
	printf("So tien doi sang USD =  %lf $\n", tienvnd / usdvnd);
	printf("So tien doi sang EUR =  %lf EUR\n", tienvnd/ usdvnd / eurusd);
	return 0;
}

