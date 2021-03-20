#include<stdio.h>
#include<string.h>

void thuexe(int n) //n la songuoi <=20
{
    int taxi4,taxi7,xemay;
    taxi7=n/7;
    n=n%7;
    taxi4=xemay=0;
    if(n>4) taxi7++;
    else if(n>1) taxi4++;
    else xemay++;
    
    
    printf("Phuong an thue xe toi uu nhat");
    printf("\nThue %d xe Taxi 7 cho",taxi7);
    if(taxi4 > 0) printf("\nThue %d Xe Taxi 4 cho",taxi4);
    if(xemay > 0) printf("\nThue %d Xe May",xemay);
    
    int chiphi;
    chiphi=(taxi7*12+taxi4*9+xemay*5)*30;
    printf("\nTong chi phi =%d000 dong",chiphi);
}



int main()
{
	printf("So hoc sinh ");
	int n;
	scanf("%d",&n);
	thuexe(n);
}
