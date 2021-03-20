#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} node_t;
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

//check trai phai
int LeftOf_root( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    if(root->left==NULL)
        return 1;
    else return 0;
    //return value <= root->data;
}
 
int RightOf_root( const int value, const node_t* root )
{
    if(root->right==NULL)
        return 1;
    return 0;
}
// Tao nut goc
node_t* Insert_root( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }   
    if (LeftOf_root(value, root))
            root->left = Insert_root(root->left, value);
    else if (RightOf_root(value, root))
            root->right = Insert_root(root->right, value);
    else printf("Nut da co 2 con");
    return root;

}
//check post 
int Check_PostOrder(node_t* root,int value){
    if(root != NULL)
    {
        if(root->data==value)
            return 1;
        printf("\n %d",root->data);
        Check_PostOrder(root->left,value);
        Check_PostOrder(root->right,value);
    }
    else
            return 0;
    
}
//Tim kiem
//Them con vao root
void Post_Search(node_t* root,int value_root,int value){
    int value_con;
    if(root != NULL)
    {
        value_con=value;
        if (Check_PostOrder(root,value)==1)
        {   
            do{
                printf("Da co phan tu j: %d trong cay",value_con);
                printf("\n Nhap lai con: ");
                scanf("%d",&value_con);
            }while(Check_PostOrder(root,value_con)==1);             
        }
        
        Post_Search(root->left,value_root,value_con);
        Post_Search(root->right,value_root,value_con);
        if(root->data==value_root){            
            if(root->left==NULL )
                root=Insert_root(root,value_con);
            else if(root->right==NULL )
                root=Insert_root(root,value_con);
            else printf("Nut da co 2 con\n");
        }

    }   
}
 
//delete
/*
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( root->left != NULL)
        root->left = Delete( root->left, value );
    else if ( root->left != NULL )
        root->right = Delete( root->right, value );
    else if ( root->left == NULL&&root->right==NULL ){
            free( root );
    }
    return root;
}
*/
node_t* Delete_root( node_t* root, int value ){
    Delete_root(root->left, value);
    Delete_root(root->right, value);
    if (root->data == value){
        free(root->right);
        free(root->left);
    }
}

// tam in con chau
void conChauOrder(node_t * root,int value){
    conChauOrder(root->left ,value);
    conChauOrder(root->right ,value);
    if (root->data == value){
        InOrder(root);
    }
} 


int main()
{
    node_t* root = NULL;
    int option = 0;
    int n = 0;
    do
    {
        printf("\n Menu \n"
               "\n====Nhap vao root bat ky de thuc hien chuc nang===="
               "\n0 -   In cay nhi phan"
               "\n1 -   Nhap vao root(gia ti cua nut goc trong cay)   "
               "\n2 -   Nhap (i,j) de thiet lap j la nut con cua i"
               "\n3 -   Hien thi cac nut con/chau cua nut i"
               "\n4 -   Nhap i va xoa phan tu con/chau cua i(neu co)"
               "\n\n5 - EXIT\n\n");
               

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {   
            case 0:
                printf("In tree_brinary:\n");
                InOrder(root);
                break;

            case 1:
                printf("++Chuc nang 1++\n");
                int value1=0;
                printf("Nhap gia tri root: ");
                do{
                    scanf("%d",&value1);
                    if( value1 < 1 || value1>9) 
                        printf("Nhap lai Root [1,9]: ");
                }while(value1 < 1 || value1>9);
                root=Insert_root(root,value1);
                break;

            case 2:
                printf("++Chuc nang 2++\n");
                int i,j;
                printf("Nhap nut va gia tri nut con (i:j)=\n");
                scanf("%d %d",&i,&j);
                if(Check_PostOrder(root,i)!=1){
                    printf("Khong co nut %d \n",i);
                    break;
                }
                Post_Search(root,i,j);
                break;

            case 3:
                printf("++Chuc nang 3++\n");
                int value3;
                printf("Nhap gia tri can tim: ");
                scanf("%d",&value3);
                conChauOrder(root,value3);
    
                break;

            case 4:
                printf("++Chuc nang 4++\n");
                int value4;
                printf("Nhap ten nut: ");
                scanf("%d",&value4);
                Delete_root(root,value4);

                break;

            case 5:
                break;
        }

    } while (option != 5);
    Free( root );
    root = NULL;
    return 0;
}