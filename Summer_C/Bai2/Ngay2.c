#include <stdio.h>
#include <string.h>
struct SV
{
    char name[51];
    char codeName[20];
    float gk,ck,hp;
};
int readFile(const char* filename, struct SV list[], int *size){
    FILE *fp;
    char s[20];
    fp=fopen(filename,"r");
    if(NULL==fp) return -1; 
    int n;
    fscanf(fp,"%d",&n);
    *size=n;
    char tmp[80];
    fgets(tmp,80,fp);
    for(int i=0; i<n; i++){
        fgets(list[i].name,51,fp);
        list[i].name[strlen(list[i].name)-1]='\0';
        fgets(list[i].codeName,20,fp);
        list[i].codeName[strlen(list[i].codeName)-1]='\0';
        fscanf(fp,"%f",&list[i].gk);
        fscanf(fp,"%f",&list[i].ck);
        fgets(tmp,80,fp);
    }
    fclose(fp);
}

void printList(const struct SV *list, int size){
    printf("\nDanh sach:");
    printf("\nSo luong: %d\n",size);
    for(int i=0; i<size; i++){
        printf("%20s %15s %4.2f %4.2f %4.2f\n",
                list[i].name,list[i].codeName,list[i].gk,list[i].ck,list[i].hp);
    }
    printf("\n==========================================\n");
}

void tin_diem(struct SV *list, int size, float grate){
    for (int i = 0; i < size; i++)
         list[i].hp = grate*list[i].gk + (1-grate)*list[i].ck;   
}

void sap_xep_theo_diem(struct SV *list, int size){
    /*
    for(int i=size;i>1;i--)
        for(int j=1;j<i;j++)
            if(list[j-1].hp<list[j].hp)
            {
                struct SV tmp = list[j-1];
                list[j-1]=list[j];
                list[j] = tmp;
            }
     */

    for(int i = 0 ; i < size ; i++ ){
        for(int j = i+1 ; j<size ;j++ ){
            if(list[i].hp < list[j].hp){
                struct SV tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

int loc_tach_File(const char* filename, struct SV *list, int size){
    FILE *fp;
    char s[80];
    fp=fopen(filename,"w");
    if(NULL == fp){
        return -1 ;
    } 
    int count = 0;
    for(int i =0; i<size ;i++){
        if(list[i].hp<4 || list[i].gk<3 || list[i].ck<3)
            count++;
    }

    for (int i = 0; i < size; i++)
    {
        if(list[i].hp<4 || list[i].gk<3 || list[i].ck<3){
            fprintf(fp,"%15s %10s %.2f %.2f %.2f\n",
                list[i].name,list[i].codeName,list[i].gk,list[i].ck,list[i].hp);
        }
    }
    fclose(fp);
    
}

int main()
{
    struct SV list[100];
    int size;
    readFile("input.txt",list,&size);
    tin_diem(list,size,0.4);
    sap_xep_theo_diem(list,size);
    printList(list,size);
    loc_tach_File("hoclai.txt",list,size);
    return 0;
}