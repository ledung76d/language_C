#include<stdio.h>
#include<string.h>

#define MAXITEM 100

struct item{
	char name[30]	;
	double price;
	int quantity;
};

struct billDetail
{
	char datetime[20];
	struct item bill[MAXITEM];
	int nitems; // so luong san pham trong bill
	int sumitem;// tong so san pham trong bill
	double tongtien;
	double vat;
	double tienphaitra;
	double tienkhachdua;
	double tienkhuyenmai;
	double tientralai;
}aBill;

void clearBuffer()
{
	 // fflush(stdin);
    
    // (clears the input buffer) 
    // while ((getchar()) != '\n'); 
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//Nhap vao thong tin bill
void readBill()
{
	printf("Nhap thong tin don hang:\n");
	printf("Ngay lap hoa don: ");
	//clearBuffer;
	gets(aBill.datetime);
	
	printf("So luong san pham: ");
	scanf("%d",&aBill.nitems);
	
	int i;
	for (i=0;i<aBill.nitems;i++)
	{
		printf("Ten san pham: ");
		clearBuffer();
		gets(aBill.bill[i].name);

		printf("Gia san pham: ");
		scanf("%lf",&aBill.bill[i].price);
		
		printf("So luong: ");
		scanf("%d",&aBill.bill[i].quantity);
	}
	printf("Tien khach tra: ");
	scanf("%lf",&aBill.tienkhachdua);
	
}

void checkout(double vat)
{
	aBill.tongtien=0;
	aBill.sumitem=0;
	int i;
	for(i=0;i<aBill.nitems;i++)
	{
		aBill.tongtien=aBill.tongtien+aBill.bill[i].price*aBill.bill[i].quantity;
		aBill.sumitem=aBill.sumitem+aBill.bill[i].quantity;
	}
	aBill.vat=aBill.tongtien*vat;
	
	aBill.tienkhuyenmai=aBill.tongtien*0.05;
	if(aBill.tongtien<200000) aBill.tienkhuyenmai=0;
	if(aBill.tienkhuyenmai>50000) aBill.tienkhuyenmai=50000;
	
	aBill.tienphaitra=aBill.tongtien+aBill.vat-aBill.tienkhuyenmai;
	aBill.tientralai=aBill.tienkhachdua-aBill.tienphaitra;
	
	printf("%30s %10d\n","Tong so san pham: ",aBill.sumitem);
	printf("%30s %10.2lf\n","Tong tien hang: ",aBill.tongtien);
	if(aBill.tienkhuyenmai>0)
	printf("%30s %10.2lf\n","Tien khuyen mai:",aBill.tienkhuyenmai);
    printf("%30s %10.2lf\n","VAT: ",aBill.vat);
    printf("%30s %10.2lf\n","Tong cong: ",aBill.tienphaitra);
    printf("%30s %10.2lf\n","Tien khach dua: ",aBill.tienkhachdua);
    printf("%30s %10.2lf\n","Tien tra lai: ",aBill.tientralai);
}

void printBill()
{
	printf("Thong tin Bill");
	printf("Thoi gian: %30s\n",aBill.datetime);
	printf("So luong mat hang: %d\n",aBill.nitems);
	int i;
	for( i=0;i<aBill.nitems;i++)
    {
        printf("%30s %10.2f %3d\n",aBill.bill[i].name,
                 aBill.bill[i].price,   aBill.bill[i].quantity);
    }
    printf("========================================\n");
	checkout(0.1);
}

int main()
{
	readBill();
	printBill();
	
}
