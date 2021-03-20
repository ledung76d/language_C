#include<stdio.h>
struct sinhVien
{
	char hoten[50];
	char SHSV[15];
	double GK;
	double CK;
	double HP;
};
void tinhdiem(struct sinhVien *pSv)
{
	pSv->HP=pSv->GK*0.3+pSv->CK*0.7;
}
int main()
{
	struct sinhVien Sv;
	Sv.GK=9;
	Sv.CK=8;
	tinhdiem(&Sv);
	printf("Diem hoc phan %.2lf",Sv.HP);
	
}
