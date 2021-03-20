#include<stdio.h>

int main() {
	double tienhang,tientru,giamtruthucte,thanhtoan;
	int traloi;
	do{
		printf("Nhap tong vao tien hang: ");
		scanf("%lf",&tienhang);
		tientru=0;
		giamtruthucte=0;
		if(tienhang>=2e5 && tienhang<1e6){
			tientru=tienhang*0.05;
			if(tientru>=20000)
				giamtruthucte=20000;
			else
				giamtruthucte=tientru;
		}
		if(tienhang>=1e6){	
			tientru=tienhang*0.06;
			if(tientru>=100000)
				giamtruthucte=100000;
			else
				giamtruthucte=tientru;
		}
		thanhtoan=tienhang-giamtruthucte+tienhang*0.01;
		printf("Tong tien: %.2lf\n",tienhang);
		printf("Thue VAT: %lf",0.01*tienhang);
		printf("Tien giam tru: %lf\n",giamtruthucte);
		printf("===========================================");
		printf("Thanh toan cua khach %.2lf\n:",thanhtoan);
		
		printf("Thuc hien tiep nhan phim 1:");
		scanf("%d",&traloi);	
	}while(traloi==1);	
}

