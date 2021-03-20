#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Information
{
    int data;
    char mkh[6];
    char Name[21];
    int tichluy,tt_tt,tt_dt;
    int thoitrang,dientu;
};
typedef struct Information KH;
struct node
{
    KH kh;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
//Khoi tao cay
Node* root=NULL;

//Tim kiem tra ve vi tri node;
Node* search(Node* root,KH kh){
    if(root==NULL) return NULL;
    else if(root->kh.data==kh.data){
        return root;
    }
    else if(root->kh.data > kh.data  ){
        return search(root->left,kh);
    }
    else if(root->kh.data < kh.data ){
        return search(root->right,kh);
    }
}

Node *Insert(Node* root,KH kh){
    if(root==NULL){
        Node * root=(Node*)malloc(sizeof(Node));
        root->kh.data=kh.data;
        strcpy(root->kh.mkh,kh.mkh);
        root->kh.dientu=kh.dientu;
        root->kh.tichluy=kh.tichluy;
        strcpy(root->kh.Name,kh.Name);
        root->kh.thoitrang=kh.thoitrang;

        root->kh.tt_tt=kh.tt_tt;
        root->kh.tt_dt=kh.tt_dt;
        root->left=NULL;
        root->right=NULL;

        return root;
    }
    if(search(root,kh)!=NULL){
        search(root,kh)->kh.tichluy += kh.tichluy;
        search(root,kh)->kh.thoitrang += kh.thoitrang;
        search(root,kh)->kh.dientu += kh.dientu;
        search(root,kh)->kh.tt_tt+=kh.tt_tt;
        search(root,kh)->kh.tt_dt+=kh.tt_dt;
        return root;
    }
    if(root->kh.data < kh.data)
    {
        root->right = Insert(root->right, kh);
    }
    if(root->kh.data > kh.data)
    {
        root->left = Insert(root->left, kh);
    }
    return root;
}
//Ham doc file
void docFile(Node * root){
    KH kh;
    FILE *fp=fopen("giaodich.txt","r");
    if(fp==NULL)
    {
        printf("Error FIlE!");
        exit(1);
    }
    while(fscanf(fp,"%s\t%s\t%d\t%d\n",kh.mkh,kh.Name,&kh.dientu,&kh.thoitrang)!=EOF){
        kh.tichluy=kh.dientu+kh.thoitrang;
        kh.tt_tt=0;
        kh.tt_dt=0;
        if(kh.dientu!=0){
            kh.tt_dt=1;
        }
        if(kh.thoitrang!=0){
            kh.tt_tt=1;
        }
        char z[10];
        strcpy(z,&kh.mkh[1]);
        kh.data=atoi(z);
        printf("%-10s%-20s%-30d%-30d",kh.mkh,kh.Name,kh.dientu,kh.thoitrang);
        root=Insert(root,kh);
        printf("%-30p\n",search(root,kh));
    }
}
void printTree(Node * root)
{
    if(root != NULL)
    {
        printTree(root->left);
        printf("\n%-10s%-20s%-30d%-30d%-30d",root->kh.mkh, root->kh.Name, root->kh.tichluy, root->kh.tt_dt, root->kh.tt_tt);
        printTree(root->right);
    }    
}

void case3(Node*root){
    KH kh;
    kh.thoitrang=-1;
    kh.dientu=-1;
    printf("Nhap ma khach hang");
    scanf("%s",kh.mkh);
    kh.tt_dt=kh.tt_tt=0;
    while(kh.thoitrang < 0 || kh.dientu < 0 || strstr(kh.Name, "@") != NULL){
        printf("Nhap ten khach hang");
        scanf("%s",kh.Name);
        printf("Nhap gia tri hang dien tu: ");
        scanf("%d", &kh.dientu);
        printf("Nhap gia tri hang thoi trang: ");
        scanf("%d", &kh.thoitrang);
    }
    
    if(kh.dientu!=0){
        kh.tt_dt=1;
    }
    if(kh.thoitrang!=0){
        kh.tt_tt=1;
    }
    kh.tichluy=kh.dientu+kh.thoitrang;
    char z[10];
    strcpy(z,&kh.mkh[1]);
    kh.data=atoi(z);
    root=Insert(root,kh);
    
}

void Showmenu(){
    
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
            docFile(root);
            break;
            case 2:
            printf("Danh sach: \n" );
            printf("%d\n",root->kh.data);
            printTree(root);
            break;
            case 3:
            case3(root);
            break;
            case 4:
            printf("Chuong trinh ket thuc!");
            exit(0);
        }
    }
}
int main(){
   
    Showmenu();
    return 0;
}