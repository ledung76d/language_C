#include<stdio.h>
int main()
{   double n=1;
    double a=3;
    while(1)
    {
        n-=1/a;
        n+=1/(a+2);
        a+=4;
        printf("%f\r",4*n);
    }
}
