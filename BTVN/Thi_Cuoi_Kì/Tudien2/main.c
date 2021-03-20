#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct TUdien
{
    char tu[20];
    char nghia[20];
};
typedef struct TUdien tudien;
tudien data[100];

//BST

typedef struct Node{
    char tu[20];
    char nghia[20];
    struct Node* left;
    struct Node* right;
}node_t;


void Free(node_t * root){
    if(root==NULL)
        return;
    Free(root->left);
    Free(root->right);
    free(root);
}
int leftOf(const tudien value,const node_t* root){
    return (strcmp(value.tu,root->tu)<0);
}
int RightOf(const tudien value,const node_t* root){
    return (strcmp(value.tu,root->tu)>0);
}

node_t* Insert(node_t*root,const tudien value){
    if(root==NULL)
    {
        node_t* node=(node_t*)malloc(sizeof(node_t));
        node->left=NULL;
        node->right=NULL;
        strcpy(node->tu,value.tu);
        strcpy(node->nghia,value.nghia);
        return node;
    }
    if(leftOf(value,root))
        root->left=Insert(root->left,value);
    else if(RightOf(value,root))
        root->right=Insert(root->right,value);
    return root;
}
void case1(int *n,node_t *root){
    FILE *fp;
    fp=fopen("dich.txt","r");
    if(fp==NULL){
        printf("FILE Error");
        exit(1);
    }
    int count=0;
    while (fscanf(fp,"%s %s\n",data[count].tu,data[count].nghia)!=EOF){
        printf("%s %s\n",data[count].tu,data[count].nghia);
        //root=Insert1(root,data[count]);
        count++;

    }
    *n=count;
    fclose(fp);
}

//
void case2(node_t * root){
    if(root!=NULL){
        printf("%10s %10s\n",root->tu,root->nghia);
        case2(root->left);
        case2(root->right);
    }
}

//case3
int search(node_t *root, tudien value){
    if (root == NULL)
        return 0;
    if (strcmp(root->tu, value.tu) == 0){
        char key[5];
        printf("Co muon nhap nd moi ko? y/n\n");
        scanf("%s",key);
        if(strcmp(key,"y")==0||strcmp(key,"Y")==0){
            printf("%s  :  ",value.tu);
            scanf("%s",value.nghia);
            strcpy(root->nghia,value.nghia);
        }
        return 1;
    }else if (leftOf(value, root) ){
        return search(root->left, value);
    }else if (RightOf(value, root) ){
        return search(root->right, value);
    }
}


node_t * Find_tu(node_t *root, char value[]){
    if (root == NULL){
        return NULL;
    }
    if (strcmp(root->tu, value) == 0){
        printf("dd");
        return root;
    }else if (strcmp(root->tu,value)>0 ){
        return Find_tu(root->left, value);
    }else if (strcmp(root->tu,value)<0 ){
        return Find_tu(root->right, value);
    }
}
//chuyen tu hoa ve thuong
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void case4(node_t *root){
    char word1[100],word[100];
    char tu[10][10];
    printf("English: ");
    gets(word);
    strcat(word," ");
    strcpy(word1,word);
    strlwr(word1);
    int value=0,j=0;
    //in kieu tach tu
    for(int i=0;i<100;i++){
        printf("%c",word1[i]);
        if(word1[i]==' ') printf("\n");
        if(word1[i]=='\0') break;
    }

    //tach tu luu vao mang roi in
    for(int i=0;i<strlen(word1);++i){
        if(word1[i]==' ')
        {
            strncpy(tu[value], &word1[j], i - j);
            tu[value][i-j] = '\0';
            j = i + 1;
            value++;
        }
    }
    /*
    for(int i=0;i<value;i++){
        printf("\n%s",tu[i]);
    }
    */
    printf("%s ",Find_tu(root,tu[0])->nghia);
    for(int i=0;i<value;i++){
        if(Find_tu(root,tu[i])!=NULL){
            printf("%s ",Find_tu(root,tu[i])->nghia);
        }else printf("<thieu tu>");
    }
    
}


int main(){
    
    node_t* root=NULL;
    int option = 0;
    int n;
    int check=0;
    do
    {
        printf("\n Menu \n"
               "\n1 -  Nap tu dien:  "
               "\n2 -  Noi dung tu dien:"
               "\n3 -  Them/Sua tu: "
               "\n4 -  Dich cau: "
               "\n5 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 5:
            break;
        case 1:
            case1(&n,root);
            for(int i=0;i<n;i++){
                root=Insert(root,data[i]);
            }
            break;
        case 2:
            printf("Danh sach: ");
            case2(root);
            break;
        case 3:
            printf("Tu: ");
            scanf("%s",data[100].tu);
            check=search(root,data[100]);
            if(check==0){
                printf("%s : ",data[100].tu);
                scanf("%s",data[100].nghia);
                root=Insert(root,data[100]);
            }
            break;
        case 4:
            clearBuffer();
            case4(root);
            break;
        }

    } while (option != 5);
    
}