#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//chuyen tu hoa ve thuong
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void tach_tu(){
    char word1[100],word[100];
    char tu[10][10];
    printf("English: ");
    gets(word);
    strcat(word," ");
    strcpy(word1,word);
    strlwr(word1);
    int value=0,j=0;
    //in kieu tach tu
    /*
    for(int i=0;i<100;i++){
        printf("%c",word1[i]);
        if(word1[i]==' ') printf("\n");
        if(word1[i]=='\0') break;
    }
    */
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
    for(int i=0;i<value;i++){
        printf("\n%s",tu[i]);
    }
     
}

void Swapstring(char *A,char *B){
    char tmp[20];
    strcpy(tmp,A);
    strcpy(A,B);
    strcpy(B,tmp);
}
int Noi_chuoi()
{
    char str[80];
    strcpy (str,"Lap ");
    strcat (str,"trinh ");
    strcat (str,"khong ");
    strcat (str,"kho!");
    puts (str);
}
int In_thuong_hoa()
{
    char str[ ] = "Lap Trinh KHONG kho!";
    printf("%s\n",strlwr (str));
    char str1[ ] = "Lap Trinh KHONG kho!";
    printf("%s\n",strupr (str1));
}
int Dao_chuoi()
{
    char name[30] = "Nguyen Van Hieu";
 
    printf("Truoc khi dao nguoc : %s\n", name);
 
    printf("Sau khi dao nguoc   : %s", strrev(name));
 
    return 0;
}
int Vitri_kitu()
{
    char string[55] = "Lap trinh khong kho";
    char *first, *last;
    first = strchr(string, 'm');
    last = strrchr(string, 'k');
    if (first != NULL)
    {
        printf("Ky tu k xuat hien lan dau tai vi tri %d\n", first - string + 1);
    }
    if (last != NULL)
    {
        printf("Ky tu k xuat hien lan dau tai vi tri %d\n", last - string + 1);
    }
}
int Tim_chuoi()
{
    char string[55] = "Lap trinh khong kho";
    char *first;
    first = strstr(string, "kho");
    if (first != NULL)
    {
        printf("Vi tri xuat hien dau tien cua \"kho\" trong \"%s\" la"
               " \"%s\"",
               string, first);
    }else{
        printf("Khong tim thay!\n");
    }
}
 

int main(){
    tach_tu();
    char A[20]="A",B[20]="B";
    printf("%s %s\n",A,B);
    Swapstring(A,B);
    printf("%s %s\n",A,B);
    //chuyen tu ki tu so sang int 
    char C[20]="2000";
    int k=atoi(C);
    printf("C= %d\n",k);
    
    

    //cac ham tron string.h
    /*
    strcat(str1,str2); noi xau 2 vao xau 1
    strcmp(str1,str2);
    strcpy(str1,str2);
    strncpy(str1,str2, n); gan n ki tu str2 vo str1
    strrev(str1) //dao nguoc ki tu str1
    */
    Noi_chuoi();
    In_thuong_hoa();
    Dao_chuoi();
    Vitri_kitu();
    Tim_chuoi();
}