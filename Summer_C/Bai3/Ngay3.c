#include<stdio.h>
#include<string.h>

struct SV
{
    char hoten[51];
    char shsv[20];
    float gk,ck,hp;
};

int read_File(const char* filename,struct SV list[],int *size){
    FILE *fp;
    fp=fopen(filename,"r");
    if(NULL == fp) return -1;
    int n;
    fscanf(fp,"%d",&n);
    *size=n;
    char tmp[20];
    fgets(tmp,20,fp);
    for(int i = 0; i < n; i++){
        fgets(list[i].hoten,51,fp);
        list[i].hoten[strlen(list[i].hoten)-1]='\0';
        fgets(list[i].shsv,20,fp);
        list[i].shsv[strlen(list[i].shsv)-1]='\0';
        fscanf(fp,"%f",&list[i].gk);
        fscanf(fp,"%f",&list[i].ck);
        fgets(tmp,20,fp);
    }
    fclose(fp);
}

void print_File(struct SV list[],int size){
    printf("Danh sach: \n");
    printf("So luong: %d\n",size);
    for (int i = 0; i < size; i++)
    {
        printf("%15s %10s %.2f %.2f %.2f\n",list[i].hoten, 
            list[i].shsv,list[i].gk,list[i].ck,list[i].hp);

    }
    printf("\n========\n");    
}

int main(){
    struct SV list[100];
    int size;
    read_File("input.txt",list,&size);
    print_File(list,size);

}