#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Information
{
    int data1;
    int data2;
} ;
typedef struct Information Element;
typedef struct NODE
{
    Element nod;
    int data;
    struct NODE *left;
    struct NODE *right;
}*node;

//node root = NULL;

node find(node root, int i)
{
    if(root == NULL) {
        return NULL;
    }
    else if(root->data == i) {return root;}
    if(find(root->left, i) == NULL) find(root->right, i); 
}

node insert_root(node root, int value)
{
    if(root==NULL){
        node root = (node)malloc(sizeof(struct NODE));
        root->data=value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
}

void insert(node root,int i,int j){
    node current=find(root,i);
    if(current == NULL) {
        printf("Khong ton tai i \n");
    }
    else if(current->left == NULL) {
        while(find(root, j) != NULL) {
            printf("Nhap lai gia tri j! \n");
            scanf("%d", &j);
        }
        current->left = insert_root(root,j);
    }
    else if(current->right == NULL) {
        while(find(root, j) != NULL) {
            printf("Nhap lai gia tri j! \n");
            scanf("%d", &j);
        }
        current->right = insert_root(root,j);
    }
    else {
        printf("i da co ca 2 con trai phai \n");
    }

}
//case 1
void enter_root(node root){
    int d = 0;
    do {
        printf("Gia tri cua Root: \n");
        scanf("%d", &d);
    } while (d < 1 || d > 10);
    root = insert_root(root, d);
}

//case 2
void enter_child(node root){
    int option=1;
    while(option==1){
        int i,j;
        printf("Gia tri cua (i, j): \n");
        scanf("%d %d", &i, &j);
        insert(root, i, j);
        printf("Tiep tuc? (Yes = 1) \n");
        scanf("%d", &option);
    }
}


void printTree(node root)
{
    printf("cai deo gi the");
    if(root != NULL)
    {
        printTree(root->left);
        printf("%-10d",root->data);
        printTree(root->right);
    }    
}
void menu(node root)
{
    int x;
    while(1)
    {
        printf("\n1. Tao root\n");
        printf("2. Chon root de nhap\n");
        printf("3. int con\n");
        printf("4. Thoat\n");
        printf("Ban chon: ");
        scanf("%d", &x);
        switch(x)
        {
            case 1:
            printf("Chac nang 1:\n");
            enter_root(root);    
            break;
            case 2:
            printf("Chac nang 2:\n");
            enter_child(root);
            break;
            case 3:
            printf("Chac nang 3:\n");
            printTree(root);
            break;
            case 4:
            printf("Chuong trinh ket thuc!");
            exit(0);
        }
    }
}
int main()
{
    node root=NULL;
    menu(root);
    return 0;
}