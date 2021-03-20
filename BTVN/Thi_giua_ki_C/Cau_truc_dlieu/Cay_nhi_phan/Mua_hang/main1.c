#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Information
{
    char mkh[6];
    char tenkh[21];
    int tichluy,thoitrang,dientu;
    int sldt,sltt;
} ;
typedef struct Information khachhang;
typedef struct NODE
{
    khachhang kh;
    struct NODE *left;
    struct NODE *right;
}*node;
node root = NULL;
node search(node root, khachhang kh)
{
    if(root == NULL)return NULL;
    else if(strcmp(root->kh.mkh,kh.mkh)==0)
    {   
        return root;
    }
    else if(strcmp(root->kh.mkh,kh.mkh)>0)
    {
        
        return search(root->left, kh);
    }
    else if(strcmp(root->kh.mkh,kh.mkh)<0)
    {   
        return search(root->right, kh);
    }
    
}
node insert(node root, khachhang kh)
{
    if(root == NULL)
    {
        node root = (node)malloc(sizeof(struct NODE));
        strcpy(root->kh.mkh, kh.mkh);
        root->kh.tichluy = kh.tichluy;
        root->kh.dientu = kh.dientu;
        strcpy(root->kh.tenkh, kh.tenkh);
        root->kh.thoitrang = kh.thoitrang;
        root->left = NULL;
        root->right = NULL;
        root->kh.sldt = kh.sldt;
        root->kh.sltt = kh.sltt;
        return root;
    }
    if(search(root, kh) != NULL)
    {
        search(root,kh)->kh.tichluy += kh.tichluy;
        search(root,kh)->kh.thoitrang = kh.thoitrang;
        search(root,kh)->kh.dientu = kh.dientu;
        search(root,kh)->kh.sldt += kh.sldt;
        search(root,kh)->kh.sltt += kh.sltt;
        return root;
    }
    if(strcmp(root->kh.mkh,kh.mkh)<0)
    {
        root->right = insert(root->right, kh);
    }
    if(strcmp(root->kh.mkh,kh.mkh)>0)
    {
        root->left = insert(root->left, kh);
    }
    return root;
}
void docfile()
{
    khachhang kh;
    FILE *fp = fopen("giaodich.txt", "r");
    if(fp == NULL)
    {
        printf("Error file!");
        return;
    }
    while(fscanf(fp,"%s\t%s\t%d\t%d\n",kh.mkh, kh.tenkh, &kh.dientu, &kh.thoitrang) != EOF)
    {
        kh.tichluy = kh.dientu + kh.thoitrang;
        kh.sldt = 0;
        kh.sltt = 0;
        if(kh.dientu != 0)
        {
            kh.sldt = 1;
        }
        if(kh.thoitrang != 0)
        {
            kh.sltt = 1;
        }
        root = insert(root, kh);
        printf("\n%-10s%-20s%-30d%-30d%-30X",search(root,kh)->kh.mkh, search(root,kh)->kh.tenkh, search(root,kh)->kh.dientu, search(root,kh)->kh.thoitrang, search(root,kh));
    }
}

void printTree(node root)
{
    if(root != NULL)
    {
        printTree(root->left);
        printf("\n%-10s%-20s%-30d%-30d%-30d",root->kh.mkh, root->kh.tenkh, root->kh.tichluy, root->kh.sldt, root->kh.sltt);
        printTree(root->right);
    }    
}
void printTree1(node root)
{
    if(root != NULL)
    {
        printTree(root->left);
        printf("\n%-10s%-20s%-30d%-30d%-30d",root->kh.mkh, root->kh.tenkh, root->kh.thoitrang, root->kh.dientu, root->kh.tichluy);
        printTree(root->right);
    }    
}


void case3()
{
    khachhang kh;
    kh.thoitrang = -1;
    kh.dientu = -1;
    
    while(kh.thoitrang < 0 || kh.dientu < 0 || strstr(kh.tenkh, "@") != NULL)
    {
        printf("Nhap ma khach hang: ");
        scanf("%s", kh.mkh);
        printf("Nhap ten khach hang: ");
        scanf("%s", kh.tenkh);
        printf("Nhap gia tri hang dien tu: ");
        scanf("%d", &kh.dientu);
        printf("Nhap gia tri hang thoi trang: ");
        scanf("%d", &kh.thoitrang);
        
    }
    kh.sldt = 0;
        kh.sltt = 0;
        if(kh.dientu != 0)
        {
            kh.sldt = 1;
        }
        if(kh.thoitrang != 0)
        {
            kh.sltt = 1;
        }
    kh.tichluy = kh.dientu + kh.thoitrang;
    root = insert(root, kh);
}
void menu()
{
    int x;
    while(1)
    {
        printf("\n1. Load transaction data\n");
        printf("2. Show Statistics Data\n");
        printf("3. Manually add transaction\n");
        printf("4. Thoat\n");
        printf("Ban chon: ");
        scanf("%d", &x);
        switch(x)
        {
            case 1:
            docfile();
            break;
            case 2:
            printf("\nDanh sach: \n");
            printTree(root);
            break;
            case 3:
            case3();
            printTree1(root);
            break;
            case 4:
            printf("Chuong trinh ket thuc!");
            exit(0);
        }
    }
}
int main()
{
    menu();
    return 0;
}