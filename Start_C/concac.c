#include <stdio.h>
#include <conio.h>

struct duLieu 
{
    int nitem; // int n=0
	int soLuong;
	int soHang[10]; 
    double giaTien;
    double tongTien;
    char tenHang[30];
    
}duLieu1[100]; // khai bao bien kieu mang de luu , nhap duoc nhieu hon'
 
//int n=0  ;   cho nay nen vuot luon vao struct  ma de ngoai chac cx dc 

void clearBuffer()
{
	int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void nhapDuLieu(){
    
    printf("Nhap vao cac loai san pham: ");
    scanf("%d",n);
    int i;
    for ( i=0;i<n;i++)
    {
    printf("Nhap ten san pham");
    clearBuffer();
    //scanf("%c",&duLieu1.tenHang[30]); cho nay len dung gét
    //int c;
    //while ((c = getchar()) != '\n' && c != EOF) { }  2 dong nay len de o tren phan nhap kieu xau
    printf("Nhap so luong : ");
    scanf("%d",&duLieu1.soLuong);
    printf("Nhap gia tien: ");
    scanf("%lf",&duLieu1.giaTien);
    }
     
}
void xuatDulieu(){
	int j;
    for ( j=0;j<duLieu1.soHang[n];j++){

    duLieu1.tongTien=duLieu1.soLuong*duLieu1.giaTien;
    printf("So tien thanh toan:%.2lf ",duLieu1.tongTien);
    }
}
int main()
{
    nhapDuLieu();
    xuatDulieu();
    return 0;
}
