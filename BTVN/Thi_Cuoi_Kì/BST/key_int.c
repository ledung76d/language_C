#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Data
{
    int data;
    char name[20];
    char name_ID[20];
    int diem1;
    int diem2; 
};
typedef struct Data DATA;

DATA dulieu[100];

typedef struct Node
{
    int data;
    char name[20];
    char name_ID[20];
    int diem1;
    int diem2; 
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
 
int LeftOf( const DATA value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value.data < root->data;
//    return value <= root->data;
}
 
int RightOf( const DATA value, const node_t* root )
{
    return value.data > root->data;
}
 
node_t* Insert( node_t* root, const DATA value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value.data;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( root->data > value ){
        return Search( root->left, value );
    }else if(  root->data < value  ){
        return Search( root->right, value );
    }
}
 
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}
 
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( root->data > value )
        root->left = Delete( root->left, value );
    else if ( root->data < value )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}
 
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
 
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
 
 
int main()
{
    node_t* root = NULL;
    for(int i=0;i<10;i++){
        dulieu[i].data=i+1;
    }
    for (int i = 0; i < 10; i++)
    {
        root = Insert( root,dulieu[i] );
    }
    
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
    dulieu[15].data=15;
    printf("\n==Thu them phan tu 15 vao BTS==\n");
    Insert(root, dulieu[15]);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
 
    printf("\n==Thu xoa phan tu 50 khoi BTS==\n");
    Delete(root, 50);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
    Free( root );
    root = NULL;
    return 0;
}
 