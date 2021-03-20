#include <stdio.h>
#include <math.h>

#define PRECISE 0.0001f

double mysqrt(int );
int main()
{
	int a;
	printf("Nhap so can tinh can bac 2: ");
	scanf("%d",&a);
	double b;
	b=mysqrt(a);
	printf("Gia tri tinh theo  bieu thuc hoi qui   %.6lf",b);
	printf("\nGia tri tinh theo ham pow trong math.h %.6lf",pow(a,0.5));
}

double mysqrt(int x)
{
    double guess = 1;
    while (fabs(guess*guess - x)/x >= PRECISE)
        guess = (x/guess + guess) / 2 ;
    return guess;
}
