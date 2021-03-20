#include <stdio.h>
#include<string.h>
#include <conio.h>
#define MAXITEM 100
const int MAXITEMS = 100;
struct duKien {
    char tenHang[30];
    int soLuong;
    double giaTien;
        };
struct duLieu {
                
                int soHang;
                struct duKien duLieu2[MAXITEM]; //? char  char duKien duLieu2[MAXITEMS];
                double tongTien;
                }duLieu1;
     
void nhapDuLieu(){
   
    printf("Nhap vao cac loai san pham: ");
    scanf("%d",&duLieu1.soHang);
    int i;
    for (i=0;i<duLieu1.soHang;i++)
    {
    printf("Nhap ten san pham");
   
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    gets (duLieu1.duLieu2[i].tenHang);
    printf("Nhap so luong : ");
    scanf("%d",&duLieu1.duLieu2[i].soLuong);
    printf("Nhap gia tien: ");
    scanf("%lf",&duLieu1.duLieu2[i].giaTien);
    }
     
}
void xuatDulieu(){
    duLieu1.tongTien=0;
    int i;
    for (i=0;i<duLieu1.soHang;i++){

    duLieu1.tongTien= duLieu1.tongTien+duLieu1.duLieu2[i].soLuong*duLieu1.duLieu2[i].giaTien;
    //printf("So tien thanh toan:%.2lf ",duLieu1.tongTien); in thi pahi de o ngoai
    }
	printf("So tien thanh toan:%.2lf ",duLieu1.tongTien); 
}

int main()
{
    nhapDuLieu();
    xuatDulieu();
    return 0;
}
