#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100
struct FILE_data
{
    int data;
    char name_key[20];
    char ID[20];
    int diem1;
    int diem2;
    int TB;
}; 
typedef struct FILE_data DATA;
DATA database[MAX];
void resetData(){
    for(int i=0;i<MAX;++i){
        database[i].data=0;
        database[i].diem1=0;
        database[i].diem2=0;
        database[i].TB=0;
        strcpy(database[i].name_key,"0");
        strcpy(database[i].ID,"0");
    }   
}
void read_file(int *n){
    FILE *fp;
    fp=fopen("file.txt","r");
    if(fp==NULL){
        printf("Error FILE?");
        exit(1);
    }
    int count=0;
    fscanf(fp,"%d",&count);
    *n=count;
    for(int i=0;i<count;++i){
        fscanf(fp,"%s\t%d\t%d\n",database[i].name_key,&database[i].diem1,&database[i].diem2);
    }
}
void In_file(int n){
    printf("Data in file:\n");
    for(int i=0;i<n;i++){
        printf("%10s%10d%10d\n",database[i].name_key,database[i].diem1,database[i].diem2);
    }
}

//Cay nhi phan
typedef struct Node
{
    int data;
    char name_key[20];
    char ID[20];
    int diem1;
    int diem2;
    int TB;
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
//DK duyet cay
int LeftOf( const DATA value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return (strcmp(value.name_key,root->name_key)<0);
//    return value <= root->data;
}
int RightOf( const DATA value, const node_t* root )
{
    return (strcmp(value.name_key,root->name_key)>0);
}
//Them node moi vao cay
node_t* Insert( node_t* root, const DATA value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        strcpy(node->name_key,value.name_key);
        strcpy(node->ID,value.ID);
        node->data=value.data;
        node->diem1=value.diem1;
        node->diem2=value.diem2;
        node->TB=value.TB;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}

//In cay 
void PreOrder(node_t* root){
    
    if(root != NULL)
    {
        //printf("%s %d ", root->tu,root->data);
        printf("%s %d %d ", root->name_key,root->diem1,root->diem2);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

//Tim kiem cay nhi phan
int Find_tudien(node_t* root,const DATA value){
    
    if(root != NULL)
    {   
        if(strcmp(root->name_key,value.name_key)==0){
            printf("\n Name key: %s",root->name_key);
            printf("\n Diem1 : %s",root->diem1);
            return 1;
        }
        else if(LeftOf( value, root )){
           return Find_tudien(root->left,value);
        }
        else if(RightOf( value, root )){
           return Find_tudien(root->right,value);
        }  
    }else
        return 0;
    
}

//


int  main(){
    resetData();
    int option = 0;
    int nfile; //so luong tu trong file
    read_file(&nfile);
    In_file(nfile);
    do
    {
        printf("\n Menu \n"
               "\n1 -   Chuc nang 1    "
               "\n2 -   Chuc nang 2    "
               "\n3 -   Chuc nang 3    "
               "\n4 -   Chuc nang 4    "
               "\n5 -   Chuc nang 5    "
               "\n6 -   Chuc nang 6    "
               "\n0 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
        
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }

    } while (option != 0);
    
}