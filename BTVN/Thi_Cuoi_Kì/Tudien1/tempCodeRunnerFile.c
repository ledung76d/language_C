#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct TuDien
{
    int data;
    char tu[20];
    char nghia[20];
}; 
typedef struct TuDien DATA;
DATA database[100];
void read_file(int *n){
    FILE *fp;
    fp=fopen("tudien.txt","r");
    if(fp==NULL){
        printf("Error FIlE?");
        exit(1);
    }
    int count=0;
    while (fscanf(fp,"%s %s\n",database[count].tu,database[count].nghia)!=EOF)
    {
        printf("%-20s %-20s\n",database[count].tu,database[count].nghia);
        database[count].data=count+1;
        count++;
    }
    *n=count+1;
}

//
typedef struct Node
{
    int data;
    char tu[20];
    char nghia[20];
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
    return (strcmp(value.tu,root->tu)<0);
//    return value <= root->data;
}
 
int RightOf( const DATA value, const node_t* root )
{
    return (strcmp(value.tu,root->tu)>0);
}
 
node_t* Insert( node_t* root, const DATA value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        strcpy(node->tu,value.tu);
        strcpy(node->nghia,value.nghia);
        node->data=value.data;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
bool Search( const node_t* root, DATA value )
{
    if ( root == NULL )
        return false;
    if(strcmp(root->tu, value.tu)==0){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}
 

 
void PreOrder(node_t* root){
    
    if(root != NULL)
    {
        //printf("%s %d ", root->tu,root->data);
        printf("%s ", root->tu);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int Find_tudien(node_t* root,const DATA value){
    
    if(root != NULL)
    {   
        if(strcmp(root->tu,value.tu)==0){
            printf("\nTu: %s",root->tu);
            printf("\nNghia: %s",root->nghia);
            return 1;
        }
        else if(LeftOf( value, root )){
            printf("%s ", root->tu);
            Find_tudien(root->left,value);
        }
        else if(RightOf( value, root )){
            printf("%s ", root->tu);
            Find_tudien(root->right,value);
        }  
    }else
        return 0;
    
}

void case1(){
   
        printf("Tu: ");
        scanf("%s",database[100].tu);
        printf("Nghia: ");
        scanf("%s",database[100].nghia);
    
}

int  main(){
    int option = 0;
    int sotu; //so luong tu trong file
    read_file(&sotu);
    node_t* root = NULL;
    for(int i=0;i<sotu;i++){
        root=Insert(root,database[i]);
    }
   
    do
    {
        printf("\n Menu \n"
               "\n1 -   ....   "
               "\n2 -   ...."
               "\n3 -   ...."
               "\n0 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("In cay:\n");
            printf("In theo thu tu cha ->con trai->con phai: ");
            PreOrder(root);
            break;
        case 2:
        printf("Them tu moi:\n");
         int option=1;
        do{
            case1();
            root=Insert(root,database[100]);
            printf("\nNhap 1 continue | 0 exit.");
            scanf("%d",&option);
        }while(option!=0);
            break;
        case 3:
        printf("Tu can dich: ");
        scanf("%s",database[99].tu);
        int k;
        k=Find_tudien(root,database[99]);
        if(k!=1) printf("\nKhong tim thay tu can tra.");
            break;
        case 4:
            break;
        }

    } while (option != 0);
}