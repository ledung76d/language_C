#include<stdio.h>
#include<string.h>

void thuexe(int songuoi) //songuoi <=20
{
    int taxi4,taxi7,xemay;
    taxi7=songuoi/7;
    songuoi=songuoi%7;
    taxi4=songuoi/4;
    xemay=songuoi%4;
    printf("Phuong an thue xe");
    printf("\nTaxi 7 cho: %d xe",taxi7);
    printf("\nTaxi 4 cho: %d xe",taxi4);
    printf("\nXe may    : %d xe",xemay);
    printf("\nTong chi phi =%d k",taxi7*12+taxi4*9+xemay*5);
}



int main()
{
	printf("So hoc sinh ");
	int n;
	scanf("%d",&n);
	thuexe(n);
}
