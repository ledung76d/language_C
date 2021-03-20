#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char TenSV[20];
    float DiemQT, DiemCK, DiemTK;
    char DiemXL;
} DiemSV;

DiemSV BangDiem[40];
int BangDiemSize = 0;

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char classify(float DiemQT, float DiemCK, float DiemTK) {
    if(DiemCK <= 3 || DiemQT <= 3) {
        return 'F';
    }
    
    if(DiemTK < 4) return 'F';
    else if(4 <= DiemTK < 5.5) return 'D';
    else if(5.5 <= DiemTK < 7) return 'C';
    else if(7 <= DiemTK < 8.5) return 'B';
    else if(8.5 <= DiemTK) return 'A';
}

void tinhDiemTKXL(int i) {
    float DiemQT = BangDiem[i - 1].DiemQT;
    float DiemCK = BangDiem[i - 1].DiemCK;
    
    BangDiem[i - 1].DiemTK = 0.4*DiemQT + 0.6*DiemCK;
    BangDiem[i - 1].DiemXL = classify(BangDiem[i - 1].DiemQT, BangDiem[i - 1].DiemCK, BangDiem[i - 1].DiemTK);
}

void insertAScore(float* score) {

    float f = -1;
    while(f < 0 || f > 10) {
        printf("*Diem phai tu 0 den 10: \n");
        clearBuffer();
        scanf(" %f", &f);
    }
    *score = f;
}

void insertScores() {
    printf("Nhap so sinh vien: \n");
    
    while(BangDiemSize < 1 || BangDiemSize > 40) {
        printf("*So sinh vien phai nam trong [1,40]. \n");
        scanf("%d", &BangDiemSize);
    }
    int i;
    for( i = 1; i <= BangDiemSize; ++i) {
        printf("Sinh vien thu %d: \n", i);
        printf("Hay nhap ten: ");
        scanf("%s",BangDiem[i - 1].TenSV);
        printf("Hay nhap Diem QT: \n");
        float f;
        insertAScore(&f);
        BangDiem[i - 1].DiemQT = f;
        printf("Hay nhap Diem CK: \n");
        insertAScore(&f);
        BangDiem[i - 1].DiemCK = f;
        tinhDiemTKXL(i);
    }
    showMenu();
}

void printAScore(int i) {
    printf("%25s%15f%15f%15f%15c\n", BangDiem[i-1].TenSV, BangDiem[i-1].DiemQT, BangDiem[i-1].DiemCK, BangDiem[i-1].DiemTK, BangDiem[i-1].DiemXL);
}

void printScores() {
    printf("%25s%15s%15s%15s%15s\n","Ten SV","Diem QT","Diem CK","Diem TK", "Diem XL");
    int i;
	for(i = 1; i <= BangDiemSize; i++) {
        printAScore(i);
    }
    showMenu();
}

void scoreDifferences() {
    int L = 1;
    printf("Nhap diem chenh lech: \n");
    while(L < 2 || L > 5) {
        printf("*Chi trong khoang [2,5] \n");
        scanf("%d", &L);
    }
    printf("%25s%15s%15s%15s%15s\n","Ten SV","Diem QT","Diem CK","Diem TK", "Diem XL");
    int i;
    for( i = 1; i <= BangDiemSize; ++i) {
        if(BangDiem[i - 1].DiemQT - BangDiem[i - 1].DiemCK >= L || BangDiem[i - 1].DiemQT - BangDiem[i - 1].DiemCK <= -L) {
            printAScore(i);
        }
    }
    showMenu();
}

void swapStudent(int i, int j) {
    char ten[20];
    strcpy(ten, BangDiem[i].TenSV);
    strcpy(BangDiem[i].TenSV, BangDiem[j].TenSV);
    strcpy(BangDiem[j].TenSV, ten);
    float qt;
    qt = BangDiem[i].DiemQT;
    BangDiem[i].DiemQT = BangDiem[j].DiemQT;
    BangDiem[j].DiemQT = qt;
    float ck;
    ck = BangDiem[i].DiemCK;
    BangDiem[i].DiemCK = BangDiem[j].DiemCK;
    BangDiem[j].DiemCK = ck;
    float tk;
    tk = BangDiem[i].DiemTK;
    BangDiem[i].DiemTK = BangDiem[j].DiemTK;
    BangDiem[j].DiemTK = tk;
    char xl;
    xl = BangDiem[i].DiemXL;
    BangDiem[i].DiemXL = BangDiem[j].DiemXL;
    BangDiem[j].DiemXL = xl;
}

void sortScores() {
	int i,j;
    for( i=0; i<BangDiemSize-1; i++)
        for(j=i+1; j<BangDiemSize; j++) {
            if (BangDiem[i].DiemTK < BangDiem[j].DiemTK) {
                swapStudent(i,j);
            }
            else if (BangDiem[i].DiemTK==BangDiem[j].DiemTK && strcmp(BangDiem[i].TenSV, BangDiem[j].TenSV) > 0) {
                swapStudent(i,j);
            }
        }
    showMenu();
}

void showMenu() {
    printf("Chuong Trinh Quan Ly Diem Mon Hoc \n 1. Nhap Diem \n 2. In Bang Diem \n 3. Chenh lech diem \n 4. Sap xep \n 5. Thoat chuong trinh \n");
    int selection = 0;
    while(selection < 1 || selection > 5) {
        printf(" Press (1,2,3,4,5) to choose:");
        scanf("%d", &selection);
    }
    switch(selection){
        case 1:
            insertScores();
            break;
        case 2:
            printScores();
            break;
        case 3:
            scoreDifferences();
            break;
        case 4:
            sortScores();
            break;
        case 5:
            return;
    }
}

int main() {
    showMenu();
}

