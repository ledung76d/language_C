#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Danhsach{
    char Phong[10];
    char Name[30];
    int tuoi;
    int Thutu;
    int huonngdan;
    int dihuongdan;
};

struct  Danhsach NV_C[50];
struct  Danhsach NV_java[50];

void reset(){
    for(int i=0;i<50;i++){
        NV_C[i].Thutu=0;
        NV_java[i].Thutu=0;
        NV_C[i].huonngdan=0;
        NV_C[i].dihuongdan=0;
        NV_java[i].huonngdan=0;
        NV_java[i].huonngdan=0;
    }
}
void Input_C(char Luachon[],int i){
    
        if(NV_C[i].Thutu==0){
        printf("Name: ");
        scanf("%s",NV_C[i].Name);
        strcpy(NV_C[i].Phong,Luachon);
        do{
            printf("Tuoi: ");
            scanf("%d",&NV_C[i].tuoi);
            if(NV_C[i].tuoi<18 ||NV_C[i].tuoi>30) printf("Invalid Age!");
        }while(NV_C[i].tuoi<18 ||NV_C[i].tuoi>30);
        
        NV_C[i].Thutu=i+1;
        printf("Nhan vien co so hieu la: %d",i+1);
    }
    
}
void Input_java(char Luachon[],int i){
        if(NV_java[i].Thutu==0){
        printf("Name: ");
        scanf("%s",NV_java[i].Name);
        strcpy(NV_java[i].Phong,Luachon);
        do{
            printf("Tuoi: ");
            scanf("%d",&NV_java[i].tuoi);
            if(NV_java[i].tuoi<18 ||NV_java[i].tuoi>30) printf("Invalid Age!");
        }while(NV_java[i].tuoi<18 ||NV_java[i].tuoi>30);
        
        NV_java[i].Thutu=i+1;
        printf("Nhan vien co so hieu la: %d",i+1);
        }  
}
//a  duoc huong dan
//b  di huong han
int case3(int a,int b){
    if(NV_C[a].Thutu==0 || NV_java[a].Thutu==0){
         printf("Invalid");
         return 1;
    } 
    if(a==b ){
         printf("Invalid");
         return 1;
    } 
    if( strcmp(NV_C[a].Phong,NV_java[b].Phong)!=0  && strcmp(NV_java[a].Phong,NV_C[b].Phong)!=0){
         printf("Invalid");
         return 1;
    } 
    if(NV_C[a].huonngdan>=3){
         printf("Invalid");
         return 1;
    }
     if(NV_java[a].huonngdan>=1){
         printf("Invalid");
         return 1;
    }
    int i,j;
    if(strcmp(NV_C[a].Phong,NV_java[b].Phong) ==0){
         printf("\n%s -|>%s\n",NV_C[a].Name,NV_C[b].Name);
         NV_C[a].dihuongdan=NV_C[a].dihuongdan+1;
         NV_C[b].huonngdan++;
    }
    if(strcmp(NV_java[a].Phong,NV_java[b].Phong) ==0){
        printf("\n%s-|>%s\n",NV_java[a].Name,NV_java[b].Name);
        NV_java[a].dihuongdan++;
        NV_java[b].huonngdan++;

    }

       
    return 0; 
    
}


void case5(int n){
    int kt=0;
    for (int i = 0; i < 15; i++)
    {   
        if(n==NV_C[i].Thutu)
        {
            printf("\n(i)Nhan vien co ten la: %s",NV_C[i].Name);
            printf("\n(ii)Nhan vien co tuoi la: %d",NV_C[i].tuoi);
            printf("\n(iii)Thuoc phong ban: %s",NV_C[i].Phong);
            printf("\n(iv)So nguoi huong dn nhan vien nay: %d",NV_C[i].huonngdan);
            printf("\n(v)So nguoi cung nhom voi han vien nay: %d",NV_C[i].dihuongdan);
            kt++;
        }
        
        if(n==NV_java[i].Thutu)
        {
            printf("\n===================\n");
            printf("\n(i)Nhan vien co ten la: %s",NV_java[i].Name);
            printf("\n(ii)Nhan vien co tuoi la: %d",NV_java[i].tuoi);
            printf("\n(iii)Thuoc phong ban: %s",NV_java[i].Phong);
            printf("\n(iv)So nguoi huong dn nhan vien nay: %d",NV_java[i].huonngdan);
            printf("\n(v)So nguoi cung nhom voi han vien nay: %d",NV_java[i].dihuongdan);
            kt++;
        }
    }
    if(kt==0)   printf("Invalid");
}


int main(){

    char Luachonphong[10];
    char Luachon1[10]="Java";
    char Luachon2[10]="C++";
    int option = 0;
    int sum_C=0;
    int sum_java=16;
    reset();
    do
    {
        printf("\n  ==Nhap  vao so bat ky de thuc hien chuc nang sau==  \n"
               "\n1 -  Nhap vao ten phong ban(C++/Java):  "
               "\n2 -  Nhap vao ten, tuoi cua nhan vien moi:"
               "\n3 -  Thiet lap B duoc A huong dan:"
               "\n4 -  Thiet lap B duoc cung nhom voi C:"
               "\n5 -  In thong tin cua mot nhan viet:"
               "\n6 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 6:
        
            break;
        case 1:
        printf("Chuc nang 1: \n");
        printf("Lua chon cua ban la: \n");

        scanf("%s",Luachonphong); 
        if(strcmp(Luachonphong,Luachon1)!=0 && strcmp(Luachonphong,Luachon2)!=0) printf("\nInvalid!!!!\n");
        
        
            break;
        case 2:
            printf("Chuc nang 2: \n");
            if(strcmp(Luachonphong,Luachon1)!=0 && strcmp(Luachonphong,Luachon2)!=0){
                printf("Yeu cau chon chuc nang 1.\n");
            }
             if(strcmp(Luachonphong,"Java")==0){
                 Input_java(Luachonphong,sum_C);
                 sum_java++;
             } 
             if(strcmp(Luachonphong,"C++")==0){
                 Input_C(Luachonphong,sum_C) ;
                 sum_C++;
             } 
            break;
        case 3:
        printf("Chuc nang 3: \n");
        int thang1,thang2;
        printf("\nNhap so hieu B va A:");
        scanf("%d %d",&thang1,&thang2);
        int ckcs=case3(thang1,thang2);
        if(ckcs==1) break;
       
        
            break;
        case 4:
        printf("Chuc nang 4: \n");
        
        int thang3,thang5;
        printf("\nNhap so hieu B va A:");
        scanf("%d %d",&thang3,&thang5);
            break;
        case 5:
        printf("Chuc nang 4: \n");
        int sohieu;
        printf("\nNhap so hieu nhan vien\n");
        scanf("%d",&sohieu);
        case5(sohieu);

            break;
        }

    } while (option != 6);
}
