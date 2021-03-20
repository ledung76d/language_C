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
    int n;
    for (int i = 0; i < 100; i++)
    {
        if(Str[i]==' '){
            n++;
        }
    }
    return n;    
}


int main(){
    char c[8];
    c[0]='b';
    c[1]='c';
    c[2]='\0';
    printf("%s",c);
    
}