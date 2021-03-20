#include<stdio.h>
#include<stdlib.h>

enum{
    SUCCESS,
    FAIL,
    MAX_ELEMENT=20
};

typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(void)
{
    FILE *fp;
    phoneaddress phonearr[MAX_ELEMENT];
    int i,n,irc;
    int reval=SUCCESS;
    printf("How many contacts do you want to enter(<20)?");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Name: ");
        scanf("%s",phonearr[i].name);
        printf("TEL: ");
        scanf("%s",phonearr[i].tel);
        printf("Email: ");
        scanf("%s",phonearr[i].email);
    }
    if((fp=fopen("phonebook.dat","w+b")) ==NULL){
        printf("Can not open %s.\n","phonebook.dat");
        reval=FAIL;
    }

    irc=fwrite(phonearr, sizeof(phoneaddress),n,fp);
    printf("fwrite return coe= %d\n",irc);
    fclose(fp);
    
}

