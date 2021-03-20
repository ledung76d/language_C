#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	double dau,s=1,n=1;
	int i= 1;
	while (1)
	{
		if (i% 2 == 0) dau = 1; else dau = -1;
		s = dau / (2 * i + 1);
		n+= s;
		i++;
	}
	 printf("%.10lf\n",n*4);
}
