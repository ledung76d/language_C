#include <stdio.h>
#include <string.h>
struct SV
{
    char hoten[51];
    char shsv[20];
    float gk,ck,hp;
};

// filename == ten file laf mang xau ky tu
// viet *filename va filename[] la tuong duong
// list la danh sach sinh vien sau khi doc
// size la so luong sinh vien doc duoc, phai truyen vao la dia chi
// chung ta muon thay doi bien size trong ham
int readFile(const char* filename, struct SV list[], int *size)
{
    FILE *fp ;
    fp = fopen (filename, "r") ;
    if(NULL==fp) return -1; //loi khi mo file
    int n; // so luong phan tu
    fscanf(fp,"%d",&n);
    *size = n;
    char tmp[80];
    fgets(tmp, 51, fp); // doc bo \r\n
    int i;
    for(i=0;i<n;i++)
    {
        fgets(list[i].hoten, 51, fp);
        list[i].hoten[strlen(list[i].hoten)-1]='\0'; // bo '\r\n'
        fgets(list[i].shsv, 20, fp);
        list[i].shsv[strlen(list[i].shsv)-1]='\0'; // bo '\r\n'
        fscanf(fp,"%f",&list[i].gk);
        fscanf(fp,"%f",&list[i].ck);
        fgets(tmp, 51, fp); // doc bo \r\n
    }
    fclose(fp);
}
// in ra noi dung danh sach vua doc duoc
void printList(const struct SV *list, int size)
{
    printf("\nDanh sach:\n");
    printf("So luong: %d\n",size);
    int i;
	for( i=0;i<size;i++)
        //printf("%s \n",list[i].hoten);
        printf("%20s %10s %5.2f %5.2f %5.2f\n",list[i].hoten, 
            list[i].shsv,list[i].gk,list[i].ck,list[i].hp);
    printf("\n========\n");
}

//gkrate la ti le % diem giua ky
void tinhdiem(struct SV *list, int size, float gkrate)
{
    int i;
	for(i=0;i<size;i++)
        list[i].hp = gkrate*list[i].gk + (1-gkrate)*list[i].ck;
}

void sapxeptheodiem(struct SV *list, int size)
{
    int i,j;
	for(i=size;i>1;i--)
        for( j=1;j<i;j++)
            if(list[j-1].hp<list[j].hp)
            {
                struct SV tmp = list[j-1];
                list[j-1]=list[j];
                list[j] = tmp;
            }
}

void locTruotraFile(const char* filename, struct SV *list, int size)
{
    FILE *fp ;
    char s[81] ;
    fp = fopen (filename, "w") ;
    if(NULL==fp) return;
    int count=0;
    int i;
	for( i=0;i<size;i++)
        if(list[i].hp<4 || list[i].gk<3 || list[i].ck<3)
            count++;
    
    fprintf(fp,"So sinh vien truot %d\n",count);
    for( i=0;i<size;i++)
        if(list[i].hp<4 || list[i].gk<3 || list[i].ck<3)
        {
            fprintf(fp,"%20s %10s %.2f %.2f %.2f\n",list[i].hoten, 
            list[i].shsv,list[i].gk,list[i].ck,list[i].hp);
        }
    fclose(fp);
}
int main()
{
    struct SV list[100];
    int size;
    readFile("input.txt",list,&size);
    tinhdiem(list,size,0.4);
    printList(list,size);
    sapxeptheodiem(list,size);
    printList(list,size);
    locTruotraFile("hoclai.txt",list,size);
    return 0;
}
