#include <stdio.h>

typedef struct ds ds;
struct ds
{ int tien;
  int nam,kyhan;
};
double tinhtien(int tien,int nam,int kyhan)
{double tong;
  double x,m;
  x=nam*12.0/kyhan;
  if(kyhan==3){m=0.047;}
  if(kyhan==6){m=0.051;}
  tong=tien;
  for(int i=1;i<=x;i++)
    {tong*=(1+m/4);}
  return tong;
}
int main()
{ ds lan[2];
  printf("Nhap so tien lan 1: ");scanf("%d",&lan[1].tien);
  printf("3 hay 5 nam lan 1: ");scanf("%d",&lan[1].nam);
  printf("ky han 3 hay 6 thang lan 1:");scanf("%d",&lan[1].kyhan);
  printf("Nhap so tien lan 2: ");scanf("%d",&lan[0].tien);
  printf("3 hay 5 nam lan 2: ");scanf("%d",&lan[0].nam);
  printf("ky han 3 hay 6 thang lan 2:");scanf("%d",&lan[0].kyhan);
  printf("chenh lech la :%f",tinhtien(lan[1].tien,lan[1].nam,lan[1].kyhan)-tinhtien(lan[0].tien,lan[0].nam,lan[0].kyhan));
}


