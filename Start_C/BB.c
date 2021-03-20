#include <stdio.h>
#include <math.h>

#define PRECISE 0.000000001f

double mysqrt(int );
double bieuthuc(int );
int main()
{
	int a;
	printf("Nhap so: ");
	scanf("%d",&a);
	bieuthuc(a);
}

double mysqrt(int x)
{
    double guess = 1.0f;
    while (fabs(guess*guess - x)/x >= PRECISE)
        guess = (x/guess - guess) / 2 + guess;
    return guess;
}
//
double bieuthuc(int a)
{
	int i;
	double sum = 0;
	for (i = 1; i <= 100; i++)
		sum = mysqrt(a + sum);
		
	printf("S(n) = %.11f", sum);	
	
}
//

