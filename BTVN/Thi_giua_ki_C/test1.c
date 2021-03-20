#include<stdio.h>
#include<string.h>

int chuyen_doi(char A[]){
    int c[6];
    for(int i=0;i<5;i++){
        c[i]=(int)A[i];
    }
    c[6]=c[0]+c[1]+c[2]+c[3]+c[4];
    return c[6];
}
struct Tumoi {
    char Tu[100];
};
struct Tumoi word[100];
int Sotu(char Str[]){
    int n;
    for (int i = 0; i < 100; i++)
    {
        if(Str[i]==' '){
            n=i+1;
            break;
        }
    }
    return n;    
}
int nSotu(char Str[]){
    int n=0;
    for (int i = 0; i < 100; i++)
    {
        if(Str[i]==' '){
            n++;
        }
    }
    return n;    
}


int main(){
    //strrev(); Dao nguoc ki tu
    //strupr(); bien chu thuong thanh hoa
    //strlwr(); Bien chu hoa thanh chu thuong
    char word1[100],word[100];
    char tu[10][10];
    printf("Tu can dich: \n");
    gets(word);
    strcat(word," ");
    strcpy(word1,word);
    strlwr(word1);
    int value=0,j=0;
    for(int i=0;i<strlen(word1);++i){
        
        if(word1[i]==' ')
        {
            strncpy(tu[value], &word1[j], i - j);
            tu[value][i-j] = '\0';
            j = i + 1;
            value++;
        }

    }
    for(int i=0;i<value+1;i++){
        printf("\n%s",tu[i]);
    }
    
}