#include<stdio.h>

#define MAXITEM 100 
const int MAXITEMS = 100;
struct item
{
    char name[30];
    double price;
    int quantity;
};

struct billDetail
{
    char datetime[20];// ngay gio lap hoa don
    struct item bill[MAXITEM];
    int nitems; // so luong san pham trong bill
    int sumitems;
    double tongtien;
    double vat;
    double khuyenmai;
    double tienphaitra;
    double tienkhachdua;
    double tientralai;
} aBill;



void clearBuffer()
{
     
    // fflush(stdin);
    
    // (clears the input buffer) 
    // while ((getchar()) != '\n'); 
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

}
// nhap vao thong tin bill
void readBill()
{
    printf("Nhap thong tin don hang:\n");
    printf("Ngay lap hoa don: ");
    //clearBuffer();
    gets(aBill.datetime);
    
    printf("So luong san pham: ");
    scanf("%d",&aBill.nitems);
    int i;
    for( i=0; i<aBill.nitems; i++)
    {
        printf("Ten san pham: ");
        clearBuffer();
        gets(aBill.bill[i].name);
        printf("Gia san pham: ");
        scanf("%lf",&aBill.bill[i].price);
        printf("So luong: ");
        scanf("%d",&aBill.bill[i].quantity);
    }
    
    printf("Tien khach dua: ");
    scanf("%lf",&aBill.tienkhachdua);
}

void checkout(double vat) // VAT thue gia tri gia tang 0.xx
{

    aBill.tongtien = 0;
    aBill.sumitems=0;
    int i;
    for( i=0;i<aBill.nitems;i++)
    {
        aBill.tongtien = aBill.tongtien +  aBill.bill[i].price*aBill.bill[i].quantity;
    	aBill.sumitems= aBill.sumitems+aBill.bill[i].quantity;
	}
    aBill.vat = aBill.tongtien*vat;
    if(aBill.tongtien<200000) aBill.khuyenmai=0;
    else if(aBill.tongtien>1000000) aBill.khuyenmai=50000;
    else aBill.khuyenmai=aBill.tongtien*0.05;
    aBill.tienphaitra = aBill.tongtien + aBill.vat-aBill.khuyenmai;
    aBill.tientralai = aBill.tienkhachdua - aBill.tienphaitra;
    
	printf("%30s %14d\n","Tong so san pham: ",aBill.sumitems);
    printf("%30s %10.2f\n","Tong tien hang: ",aBill.tongtien);
    printf("%30s %10.2f\n","VAT: ",aBill.vat);
    printf("%30s %10.2f\n","Tien Khuyen mai: ",aBill.khuyenmai);
    printf("%30s %10.2f\n","Tong cong: ",aBill.tienphaitra);
    printf("%30s %10.2f\n","Tien khach dua: ",aBill.tienkhachdua);
    printf("%30s %10.2f\n","Tien tra lai: ",aBill.tientralai);
}

void printBill()
{
    printf("Thong tin Bill: \n");
    printf("Thoi gian: %30s\n",aBill.datetime);
    printf("So luong san pham: %d\n",aBill.nitems);
    int i;
    for( i=0;i<aBill.nitems;i++)
    {
        printf("%30s %10.2f %3d\n",aBill.bill[i].name,
                 aBill.bill[i].price,   aBill.bill[i].quantity);
    }
    printf("========================================\n");
    checkout(0.1);
    //printf("Tong tien: %40.2lf\n",checkout(0.1));
}



int main()
{
    readBill();
    printBill();

    return 0;
}

