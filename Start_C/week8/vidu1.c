#include<stdio.h>
#include<string.h>

const char delimeter = ',';
void insoDeDoc1(int so) //char*
{
    char str[100]="";
    char tmp[100]="";
    char del[2];
    del[0]=delimeter;
    del[1] ='\0';
    
    int count =0;
    while(so>0)
    {
        int le = so%1000;
        so = so/1000;
        

        char snum[5];
        sprintf(snum, "%d", le);
        
        strcpy(tmp,"");
        strcat(tmp,snum);
        if(count>0) strcat(tmp,del);
        count++;
        
        strcat(tmp,str);
        strcpy(str,tmp);
    }
    printf("Gia tri so la: %s\n",str);
}

void insoDeDoc2(int so) //int array
{
    int boso[5];
    int size=0;
    while(so>0)
    {
        boso[size] = so%1000;
        so = so/1000;
        size++;
    }
    printf("Gia tri so la: ");
    int i;
    for( i=size-1;i>=0;i--)
    {
        if(i>0)
            printf("%d%c",boso[i],delimeter);
        else
            printf("%d\n",boso[i]);
    }
    
}

int main ()
{
    printf("Cach 1:\n");
    insoDeDoc1(14543435);
    insoDeDoc1(14);
    insoDeDoc1(14545);
    
    printf("Cach 2:\n");
    insoDeDoc2(14543434);
    insoDeDoc2(14);
    insoDeDoc2(14545);
  return 0;
}

