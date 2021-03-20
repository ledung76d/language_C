#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct danhsach{
    char IT[10];
    int thutu;
    char Name[10];
    int tuoi;
    int duoc_hd;
    int nhom;
};
struct danhsach NV[31];

void  case2(char Luachon[],int *C,int *Java,int n){
    printf("\nName: ");
    scanf("%s",NV[n].Name);
    do{
        printf("Tuoi: ");
        scanf("%d",&NV[n].tuoi);
        if(NV[n].tuoi<18||NV[n].tuoi>30)    printf("InvalidAge\n");
    }while(NV[n].tuoi<18||NV[n].tuoi>30);

    strcpy(NV[n].IT,Luachon);
    NV[n].thutu=n;
    printf("So hieu cua nhan vien la: %d",n);
     NV[n].nhom=NV[n].duoc_hd=0;
    if(strcmp(Luachon,"Java")==0)   *Java=*Java+1;
    else    *C=*C+1;
}


void case5(int n){  
    printf("\n(i)Nhan vien co ten la: %s", NV[n].Name);
    printf("\n(ii)Nhan vien co tuoi la: %d", NV[n].tuoi);
    printf("\n(iii)Thuoc phong ban: %s", NV[n].IT);
    if( NV[n].duoc_hd!=0)
        printf("\n(iv)So nguoi huong dan nhan vien nay: %d", NV[n].duoc_hd);
    if( NV[n].nhom!=0)
        printf("\n(v)So nguoi cung nhom voi han vien nay: %d", NV[n].nhom);
}


int main(){
    int options;
    char Luachon[10];
    int SumC=0;
    int SumJava=0;
    int Sothutu=1;
    int A,B;
    do{
        printf("\n\nNhap vao so bat ki de thuc hien chuc nang sau:\n");
        printf("1.Nhap vao ten phong ban(C++/Java)\n");
        printf("2.Nhap vao ten, tuoi nhan vien moi:\n");
        printf("3.Thiet lap B duoc A huong dan:\n");
        printf("4.Thiet lap B duoc cung nhom voi C:\n");
        printf("5.In thong tin cua mot nhan vien:\n");
        printf("6.Exit\n");
        printf("\nLua chon : ");
        scanf("%d",&options);

        switch (options)
        {
        case 6:
            break;
        case 1:
            printf("Lua chon: ");
            scanf("%s",Luachon);
            if(strcmp(Luachon,"C++")!=0&&strcmp(Luachon,"Java")!=0)     printf("Invalid\n");
            else    printf("Ten phong %s",Luachon);

            break;
        case 2:
            if(strcmp(Luachon,"C++")!=0&&strcmp(Luachon,"Java")!=0){
                printf("De nghi chon chuc nang 1");
                break;
            }
            if(SumC>=15||SumJava>=15){
                printf("Full\n");
                break;
            } 
            printf("Phong %s\n",Luachon);
            case2(Luachon,&SumC,&SumJava,Sothutu);
            Sothutu++;   

            break;
        case 3:
            printf("So hieu B va A:");
            
            scanf("%d %d",&B,&A);
            if(NV[B].IT=="C++"&&NV[B].duoc_hd>=3){
                printf("Invalid\n");
                break;
            } 
            if(NV[B].IT=="Java"&&NV[B].duoc_hd==1){
                printf("Invalid\n");
                break;
            }  
            
            if(A!=B && strcmp(NV[A].IT,NV[B].IT)==0){
                printf("%s -|> %s",NV[A].Name,NV[B].Name);
                NV[B].duoc_hd++;
            }else{
                printf("Invalid\n");
                break;
            }   
            
            break;
        case 4:
            printf("So hieu B va C:");
            int C;
            scanf("%d %d",&B,&C);
            if(strcmp(NV[B].IT,"C++")==0||strcmp(NV[C].IT,"C++")==0){
                printf("Error C++\n");
                break;
            }
            if(C!=B&&strcmp(NV[B].IT,NV[C].IT)==0){
                printf("%s<===>%s",NV[B].Name,NV[C].Name);
                NV[B].nhom++;
                NV[C].nhom++;
            }
            
            break;
        case 5:
            printf("So hieu nhan vien: ");
            int kkk;
            scanf("%d",&kkk);
            if(kkk!=NV[kkk].thutu){
                printf("Invalid\n");
                break;
            }
            case5(kkk);
            break;
        }
    }while(options!=6);
}