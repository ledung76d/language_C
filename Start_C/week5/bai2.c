//Tinh tong so tien phai tra khi vay tra gop ngan hang
#include <stdio.h>

int main()
{
    double tienvay,laisuat,tientragop1,tientragop2;
    int traloi;
    
    do
    {   printf("Nhap vao so tien vay");
    	scanf("%lf",&tienvay);
    	//Tinh tien tra gop theo 10 nam
    	int i;
    	double a;
    	a=1;
    	for(i=1;i<=10;i++){
    		a=a*(1+0.12);
		}
    	tientragop1=(tienvay*a*0.12)/(a-1)// tien tra gop moi nam trong 10 nam
    	//Tinh tien tra gop theo 20 nam
        	
		printf("Thuc hien tiep nhan phim 1: ");
        scanf("%d",&traloi);
        printf("\f");
    }
    while(traloi==1);
    
    return 0;
}

