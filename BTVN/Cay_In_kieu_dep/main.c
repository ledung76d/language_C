#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int **A; // our 2d array

typedef int elmType;
typedef struct nodeType
{
    elmType element;
    struct nodeType *left, *right;
} node_Type;
typedef struct nodeType *treetype;

void write(int pp, int offset, node_Type *root, char *side, int level);
int height(treetype tree);
void displayTree(node_Type *root);

// ham in cay
void displayTree(node_Type *root)
{
    int i, j;
    int a, b;
    int h = height(root);
    int nn = pow(2, h);
    a = h - 2 > 0 ? pow(2, h - 2) : 1;
    b = h - 2;
    printf("height = %d\n  max nodes = %d\n\n\n", h, nn);
    A = NULL;

    A = (int **)malloc((h + 1) * sizeof(int *)); // we need h+1 rows indexed at 1:h+1
    for (int i = 1; i <= h; i++)
        A[i] = (int *)malloc((nn) * sizeof(int)); // we need nn columns indexed at 1:nn

    for (i = 1; i <= h; i++)
        for (j = 1; j < nn; j++)
            A[i][j] = 0;

    write(nn, (nn) / 2, root, "left", 1); // Writes the entire tree in a 2d matrix A

    // Displaying the 2d matrix
    for (i = 1; i <= h; i++)
    {
        for (j = 1; j < nn; j++)
        {
            if (A[i][j] != 0)
                printf("%d", A[i][j]);
            else
                printf(" ");
        }
        printf("\n");

        for (int n = 1; n < a; n++)
        {
            for (j = 1; j < nn; j++)
            {
                if (A[i][j + n] != 0 && j + n < nn && A[i + 1][j + n - a] != 0)
                    printf("/");
                else if (A[i][j - n] != 0 && j - n > 0 && A[i + 1][j - n + a] != 0)
                    printf(" \\");
                else
                    printf(" ");
            }
            printf("\n");
        }
        b--;
        a = pow(2, b);
        if (i == h - 1)
        {
            for (j = 1; j < nn; j++)
            {
                if (A[i][j + 1] != 0 && j + 1 < nn && A[i + 1][j] != 0)
                    printf("/");
                else if (A[i][j - 1] != 0 && j - 1 > 0 && A[i + 1][j] != 0)
                    printf(" \\");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    for (int i = 0; i <= h; i++)
        free(A[i]);
    free(A);
}

void write(int pp, int offset, node_Type *root, char *side, int level)
{

    if (root == NULL)
        return;

    if (strcmp(side, "left") == 0)
    {
        A[level][pp - offset] = root->element;

        write(pp - offset, offset / 2, root->left, "left", level + 1);
        write(pp - offset, offset / 2, root->right, "right", level + 1);
    }
    else
    {
        A[level][pp + offset] = root->element;
        write(pp + offset, offset / 2, root->left, "left", level + 1);
        write(pp + offset, offset / 2, root->right, "right", level + 1);
    }
}

int height(treetype tree)
{

    if (tree)
    {
        int lheight = height(tree->left);
        int rheight = height(tree->right);
        // if (lheight > rheight)
        //     return lheight + 1;
        // else
        //     return rheight + 1;

        return 1 + (lheight > rheight ? lheight : rheight);
    }
    return 0;
}

// ket thuc ham in cay

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
 
int LeftOf( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
//    return value <= root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
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
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
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
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
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
  
    root = Insert( root, 25 );
    root = Insert( root, 15 );
    root = Insert( root, 50 );
    root = Insert( root, 10 );
    root = Insert( root, 22 );
    root = Insert( root, 35 );
    root = Insert( root, 70 );
    root = Insert( root, 4  );
    root = Insert( root, 12 );
    root = Insert( root, 18 );
    root = Insert( root, 24 );
    root = Insert( root, 31 );
    root = Insert( root, 44 );
    root = Insert( root, 66 );
    root = Insert( root, 90 );
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);
 
    printf("\n==Thu them phan tu 15 vao BTS==\n");
    Insert(root, 15);
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
 
    printf("\n\n\n");
    displayTree(root);
 
    Free( root );
    root = NULL;
    return 0;
}