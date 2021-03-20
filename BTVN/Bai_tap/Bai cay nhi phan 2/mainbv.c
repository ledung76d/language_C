#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Information
{   
    int data;
    char MaSo[6];
    char Name[21];
    int tichluy;
    int thoitrang;
    int dientu;
    
};
typedef struct Information KH; 

 
typedef struct Node
{
    int data;
    char MaSo[6];
    char Name[20];
    int  tichluy;
    int thoitrang;
    int dientu;
    int tichluy_thoitrang;
    int tichluy_dientu;
    struct Node* left;
    struct Node* right;
} node_t;
 
//Ham chuyen ma ky tu sang ma so
int chuyendoi(char a[])
{   
    int data[5];
    for(int i=0;i<6;i++){
        data[i]=(int)a[i];
    }
    data[5]=data[0]+data[1]+data[2]+data[3]+data[4];
    return data[5];
}


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
 
node_t* Insert( node_t* root, int value ,const KH KhachH)
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        strcpy(node->MaSo,KhachH.MaSo);
        strcpy(node->Name,KhachH.Name);
        node->thoitrang=KhachH.thoitrang;
        node->dientu=KhachH.dientu;
        if(KhachH.thoitrang!=0) node->tichluy_thoitrang=1;
        if(KhachH.dientu!=0) node->tichluy_dientu=1;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value ,KhachH);
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value ,KhachH);
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
        PreOrder(root->left);
        printf("%10s %10s %10d %10d \n", root->Name,root->MaSo,root->dientu,root->thoitrang);
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

void PostOrders(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%10s %10s %10d %10d ", root->Name,root->MaSo,root->dientu,root->thoitrang);
    }
}


bool Search_Kh( node_t* root, int value,const KH KhachH )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        root->dientu=root->dientu+KhachH.dientu;
        root->thoitrang=root->thoitrang+KhachH.thoitrang;
        root->tichluy=root->tichluy+KhachH.tichluy;
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}

bool Search_Khdd( node_t* root, int value,const KH KhachH )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        printf("%30X\n",root);
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}


int main()
{
    node_t* root = NULL;
    FILE *fp; 

    int option = 0;
    int i, j;
    int n = 0;
    do
    {
        printf("\n Menu \n"
               "\n1 -   Load transaction data   "
               "\n2 -   Show Statistics data"
               "\n3 -   Manually add transaction"
               "\n4 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 4:

            break;

        case 1:
            printf(" Load transaction data");
            fp=fopen("giaodich.txt","r");
            if (fp == NULL)
            {
                printf("Error file");
                exit(1);
            }
            KH KHs;
            char c[6];
            while (fscanf(fp, "%s", c) != EOF)
            {   
                strcpy(KHs.MaSo,c);
                fscanf(fp, "%s\t%d\t%d\n", KHs.MaSo, KHs.Name, &KHs.dientu, &KHs.thoitrang);
                KHs.tichluy = KHs.dientu + KHs.thoitrang;
                //printf("\n%-10s%-20s%-30d%-30d",kh.mkh, kh.tenkh, kh.dientu, kh.thoitrang);
                KHs.data = chuyendoi(KHs.MaSo);
                printf("\n%-10s %-10s %-10d %-10d", KHs.MaSo, KHs.Name, KHs.dientu, KHs.thoitrang);
                //if(Search(root,KHs.data)==true) Search_Kh(root,KHs.data,KHs);
                //else root = Insert(root,KHs.data,KHs);
                //Search_root(root,KHs.data);
                //if(root != NULL) printf("%30X\n",root);
            //Search_Khdd(root,KHs.data,KHs);
            }
            break;

        case 2:
            printf("Show Statistics data\n");
            PreOrder(root);
            break;

        case 3:
            printf("Manually add transaction");
            break;
        }

    } while (option != 4);

    fclose(fp);
    Free( root );
    root = NULL;
    return 0;
}