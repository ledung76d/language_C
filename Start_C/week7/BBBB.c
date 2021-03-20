#include <stdio.h>
#include <math.h>

#define PRECISE 0.0001f

double mysqrt(int );
double bieuthuc(int );
int main()
{
	int a;
	printf("Nhap so: ");
	scanf("%d",&a);
	bieuthuc(a);
	printf("\n%f",mysqrt(4));
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
	double un=0;
	int i;
	for(i=0;i<100;i++){
		un=sqrt(un+a);
	}
	printf("Gia tri cua Un = %lf",un);
	
}
//

