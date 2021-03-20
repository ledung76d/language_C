#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Information
{   
    int stt;
    char MSo[6];
    char Name[21];
    int thoitrang,dientu;
    int tichluy,tt_thoitrang,tt_dientu;
};
typedef struct Information KHang;

typedef struct Node
{
    int value;
    KHang data;
    struct Node* left;
    struct Node* right;
}node_t;
node_t* Insert_root(node_t* root, const int value){

}

void Showmenu(){
    FILE *fp;
    struct Information KH; 
    struct Information VN[100]; 
    fp=fopen("vanban.txt","r");
    if(fp==NULL){
        printf("<Error file>");
       exit(1);
    }
    int count=0;
    char c[6];
    while(fscanf(fp,"%s",c) != EOF){
        strcpy(KH.MSo,c);
        fscanf(fp,"%s\t%d\t%d\n",KH.Name,&KH.thoitrang,&KH.dientu);
        strcpy(VN[count].MSo,KH.MSo);
        strcpy(VN[count].Name,KH.Name);
        VN[count].thoitrang=KH.thoitrang;
        VN[count].dientu=KH.dientu;
        count++;
        //printf ("%10s %-20s %-15d %-15d\n",KH.MSo,KH.Name,KH.thoitrang,KH.dientu);
    }
    for(int i=0;i<count;i++){
        printf ("%10s %-20s %-15d %-15d\n",VN[i].MSo,VN[i].Name,VN[i].thoitrang,VN[i].dientu);
    }
    //printf ("%10s %20s %-30d %-30d",KH.MSo,KH.Name,KH.thoitrang,KH.dientu);
    printf("Kq: %d",count);
}

int main(){
    Showmenu();
    return 0;
}