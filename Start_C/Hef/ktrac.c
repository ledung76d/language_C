#include<stdio.h>
#include<string.h>
typedef struct {
char TenSV[20];
float DiemQT, DiemCK, DiemTK;
char DiemXL;
} DiemSV;
DiemSV student1[40];
int nsize,xacnhan=0; // So luong sinh vien

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void nhapDiem(){
	do{
		printf("So luong sinh vien nam trong[1,40]: ");
		scanf("%d",&nsize);
	}while(nsize>40 || nsize<0);	
		
	int i;
	for(i=0;i<nsize;i++){
		printf("Sinh vien thu %d:",i+1);
		printf("\nTen sinh vien: ");
		clearBuffer();
		gets(student1[i].TenSV);
		
		
		printf("\nDiem qua trinh: ");
		do{
			printf("\nDiem phai tu 0 den 10:");
			scanf("%f",&student1[i].DiemQT);

	    }while(student1[i].DiemQT>10||student1[i].DiemQT<0);
		
		printf("\nDiem cuoi ki: ");
			do{
			printf("\nDiem phai tu 0 den 10:");
			scanf("%f",&student1[i].DiemCK);

	    }while(student1[i].DiemCK>10||student1[i].DiemCK<0);
		
		student1[i].DiemTK=student1[i].DiemQT*0.4+student1[i].DiemCK*0.6;

		if(student1[i].DiemTK>=8.5) student1[i].DiemXL= 'A';
			else if(student1[i].DiemTK>=7) student1[i].DiemXL= 'B';
			else if(student1[i].DiemTK>=5.5) student1[i].DiemXL= 'C';
			else if(student1[i].DiemTK>=4) student1[i].DiemXL= 'D';
			else student1[i].DiemXL= 'F';
		if(student1[i].DiemCK<=3 || student1[i].DiemQT<=3) 
			student1[i].DiemXL='F'; 					
	}

	xacnhan=1;
}

void inbangdiem(){
	if(xacnhan==0) printf("\nChua co du lieu diem sinh vien.\n");
	else{
		printf("%25s %10s %10s %10s %10s","Ten SV","Diem QT","DiemCK","Diem TK","Xep Loai");
		int i;
		for(i=0;i<nsize;i++)
		printf("\n%25s %10.1f %10.1f %10.1f %10c",student1[i].TenSV,student1[i].DiemQT,student1[i].DiemCK,student1[i].DiemTK,student1[i].DiemXL);
	}	
}
void checkDiem(){
	int L=-1;
	while(L<2||L>5){
		printf("Diem chenh lech L [2,5]:");
		scanf("%d",&L);
	}
	float chenhlech;
	printf("%25s %10s %10s %10s %10s","Ten SV","Diem QT","DiemCK","Diem TK","Xep Loai");
	int i;
	for(i=0;i<nsize;i++){
		chenhlech=student1[i].DiemCK-student1[i].DiemQT;
		if(chenhlech<0) chenhlech=-chenhlech;
		if(chenhlech>=L)	
		printf("\n%25s %10.1f %10.1f %10.1f %10c",student1[i].TenSV,student1[i].DiemQT,student1[i].DiemCK,student1[i].DiemTK,student1[i].DiemXL);
	}
	
}

void swapping(){
	int i,j;
	DiemSV tmp;
	
	for(i=0;i<nsize;i++){
		for(j=i+1;j<nsize;j++){
			if(student1[i].DiemTK < student1[j].DiemTK){
				tmp.DiemTK=student1[i].DiemTK;
				student1[i].DiemTK=student1[j].DiemTK;
				student1[j].DiemTK=tmp.DiemTK;
				
				tmp.DiemQT=student1[i].DiemQT;
				student1[i].DiemQT=student1[j].DiemQT;
				student1[j].DiemQT=tmp.DiemQT;
				
				tmp.DiemCK=student1[i].DiemCK;
				student1[i].DiemCK=student1[j].DiemCK;
				student1[j].DiemCK=tmp.DiemCK;
				
				tmp.DiemXL=student1[i].DiemXL;
				student1[i].DiemXL=student1[j].DiemXL;
				student1[j].DiemXL=tmp.DiemXL;
				
				strcpy(tmp.TenSV,student1[i].TenSV);
				strcpy(student1[i].TenSV,student1[j].TenSV);
				strcpy(student1[j].TenSV,tmp.TenSV);				
			}
		}
	}
}

void chuongTrinhQuanLi(){
	int value;
	value=0;
	while(value!=5){
		printf("\nChuong Trinh Quan Ly Diem Mon Hoc\n");
		printf("1. Nhap Diem\n");
		printf("2. In Bang Diem\n");
		printf("3. Chenh lech diem\n");
		printf("4. Sap xep\n");
		printf("5. Thoat chuong trinh\n");
		printf("Press (1,2,3,4,5) to choose: ");
		scanf("%d",&value);
		switch(value){
		
			case 1:  
				nhapDiem();
				break;
			case 2:
				inbangdiem();
				break;
			case 3:
				checkDiem();
				break;
			case 4:
				swapping();
				break;
			case 5: 
				printf("Ban da thoat chuong trinh!");
				break;
		}
	}
}

int main(){
	
	chuongTrinhQuanLi();
}
