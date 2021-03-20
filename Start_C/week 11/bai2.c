#include <stdio.h>
#include <string.h>

struct meNu
{
    char maSp[20];
    char nameSp[20];
    float price;
};
//
int readFile(const char* filename, struct meNu list[], int *size)
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
        fgets(list[i].maSp, 51, fp);
        list[i].maSp[strlen(list[i].maSp)-2]='\0'; // bo '\r\n'
        fgets(list[i].nameSp, 20, fp);
        list[i].nameSp[strlen(list[i].nameSp)-2]='\0'; // bo '\r\n'
        fscanf(fp,"%f",&list[i].price);
        fgets(tmp, 51, fp); // doc bo \r\n
    }
    fclose(fp);
}

void printList(const struct meNu *list, int size)
{
    printf("\nDanh sach:\n");
    printf("So luong: %d\n",size);
    int i;
    for( i=0;i<size;i++)
        //printf("%s \n",list[i].hoten);
        printf("%20s %20s %.2f\n",list[i].maSp, 
            list[i].nameSp,list[i].price);
    printf("\n========\n");
}


int main()
{
    struct meNu list[100];
    int size;
    readFile("menu.txt",list,&size);
    printList(list,size);
}
