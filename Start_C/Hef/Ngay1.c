#include<stdio.h>
int main()
{
	int ma;
	do{
		printf("Cho ma can chuyen : ");
		scanf("%d",&ma);
		switch(ma)
		{
			case 0: printf("\n Cau truc du lieu");
				break;
			case 1: printf("\n Tri tue nhan tao");
				break;
			case 2: printf("\n Mo phong");
				break;
			case 3: printf("\n Xac xuat");
				break;
		}
		printf("\nCo tiep tuc khong? (Y/N)\n");
	}while(toupper(getch())!='N');
}
