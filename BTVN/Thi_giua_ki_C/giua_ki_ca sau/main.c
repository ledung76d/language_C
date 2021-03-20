#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct File
{
    char dir_name[10];
    char dir_namecon1[10];
    char dir_namecon2[10];
    char dir_namecon3[10];
    char dir_namecon4[10];
};
struct File Data[100];
int file_name[100];
int check_dir(int n,char Name[]){
    int check=0;
    for(int i=0;i<n;i++){
        if(strcmp(Name,Data[i].dir_name)==0)    check=1; 
    }
    return check;
}
void reset(){
    for(int i=0;i<100;i++){
        file_name[i]=0;
        strcpy(Data[i].dir_name,"0");
        strcpy(Data[i].dir_namecon1,"0");
        strcpy(Data[i].dir_namecon2,"0");
        strcpy(Data[i].dir_namecon3,"0");
        strcpy(Data[i].dir_namecon4,"0");
    }
}
int check_filemax(int Arr[]){
    int check=Arr[0];
    for(int i=0;i<100;i++){
        if(Arr[i]==0) break;
        if(Arr[i]>check)    check=Arr[i];
    }
    return check;
}
int case1(){
    int option=1;
    char g[10];

    int n=0;
    do{
        printf("\nName of directory: ");
        scanf("%s",g);
        if(strcmp(g,"0")==0){
            option=0;
        }else{ 
        if(check_dir(n,g)){
            printf("\nInvalid\n");
            break;
        }
        strcpy(Data[n].dir_name,g);
        printf("Created: %s",Data[n].dir_name);
        
        n++;
        }
    }while(option!=0);
    return n;
}

int case2(){
    int n;
    for(int i=0;i<100;i++){
        printf("\nName of file: ");
        scanf("%d",&file_name[i]);
        if(file_name[i]==0) break;
        for(int j=0;j<i;j++){
            if(file_name[i]==file_name[j]) file_name[i]=check_filemax(file_name)+1;
        }
        printf("\nCreated: %d.txt",file_name[i]); 
        n=i+1;
    }
    return n;
}
void case3(int n){
    char name[10],name_con[10];
    printf("Name of parent directory: ");
    scanf("%s",name);
    int check=0;
    int dir;
    for(int i=0;i<n;i++){
        if(strcmp(name,Data[i].dir_name)==0){
            check=1;
            dir=i;
        } 
    }
    
    if(check==1&&strcmp(name,"0")!=0){
        printf("Name of subdirectory: ");
        scanf("%s",name_con);
        if(strcmp(name_con,Data[dir].dir_namecon1)==0
        ||strcmp(name_con,Data[dir].dir_namecon2)==0
        ||strcmp(name_con,Data[dir].dir_namecon3)==0
        ||strcmp(name_con,Data[dir].dir_namecon4)==0) 
            printf("Trung ten");  
        else{
            if(strcmp("0",Data[dir].dir_namecon1)==0){
                strcpy(Data[dir].dir_namecon1,name_con);
                printf("Create: %s/%s",name,name_con);
            }else if(strcmp("0",Data[dir].dir_namecon2)==0){
                strcpy(Data[dir].dir_namecon2,name_con);
                printf("Create: %s/%s",name,name_con);
            }else if(strcmp("0",Data[dir].dir_namecon3)==0){
                strcpy(Data[dir].dir_namecon3,name_con);
                printf("Create: %s/%s",name,name_con);
            }else if(strcmp("0",Data[dir].dir_namecon4)==0){
                strcpy(Data[dir].dir_namecon4,name_con);
                printf("Create: %s/%s",name,name_con);
            }
        }  
    }else printf("\nInvalid\n");  
    
}
void case4(int n_dir){
    char name[10];
    int check=0;
    while(1){
        printf("\nDelete the dir: ");
        scanf("%s",name);
        if(strcmp(name,"0")==0) break;
        
        for(int i=0;i<n_dir;i++){
            if(strcmp(name,Data[i].dir_name)==0){
                strcpy(Data[i].dir_name,"0");
                check=1;
                printf("\nDelete.");
            }   
        }
        if(check!=1){
            for(int i=0;i<n_dir;i++){
            if(strcmp(name,Data[i].dir_namecon1)==0){
                strcpy(Data[i].dir_namecon1,"0");
                check=1;
                printf("\nDelete.");
            }   
            if(strcmp(name,Data[i].dir_namecon2)==0){
                strcpy(Data[i].dir_namecon2,"0");
                check=1;
                printf("\nDelete.");
            }   
            if(strcmp(name,Data[i].dir_namecon3)==0){
                strcpy(Data[i].dir_namecon3,"0");
                check=1;
                printf("\nDelete.");
            }  
            if(strcmp(name,Data[i].dir_namecon4)==0){
                strcpy(Data[i].dir_namecon4,"0");
                check=1;
                printf("\nDelete.");
            }   
            }
         }else if(check==0) printf("\nInvalid");
    }
}

void case5(int n_file){
    int dele;
    int check=0;
    while(1){
        printf("Delete the file: ");
        scanf("%d",&dele);
        if(dele==0) break;
        for(int i=0;i<n_file;i++){
            if(dele==file_name[i]){
                file_name[i]=0;
                check=1;
            }   
        }
        if(check==0) printf("\nInvalid");

    }
       

}

void case6(int n_file,int n_dir){
    printf("Exam: \n");
    for(int i=0;i<n_file;i++){
        if(file_name[i]==0) continue;
        printf("%20d.txt\n",file_name[i]);
    }
    for(int i=0;i<n_dir;i++){
        if(strcmp(Data[i].dir_name,"0")==0) continue;
            printf("%20s\n",Data[i].dir_name);
        if(strcmp(Data[i].dir_namecon1,"0")!=0) 
            printf("%40s\n",Data[i].dir_namecon1);
        if(strcmp(Data[i].dir_namecon2,"0")!=0) 
            printf("%40s\n",Data[i].dir_namecon2);
        if(strcmp(Data[i].dir_namecon3,"0")!=0) 
            printf("%40s\n",Data[i].dir_namecon3);
        if(strcmp(Data[i].dir_namecon4,"0")!=0) 
            printf("%40s\n",Data[i].dir_namecon4);    
    }
}

int main(){
    int option = 0;
    reset();
    int n_dir=0;
    int n_file=0;
    do
    {
        printf("\n ====Program to manage File and Directory=====  \n"
               "\n1 -   Create new directory:   "
               "\n2 -   Create new file in a directory: "
               "\n3 -   Create sub directory: "
               "\n4 -   Delete a directory: "
               "\n5 -   Delete a file: "
               "\n6 -   Print list of files and subdirectories: "
               "\n7 -   Quit\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 7:
            break;
        case 1:
            n_dir=case1();
            break;
        case 2:
            n_file=case2();
            break;
        case 3:
            case3(n_dir);
            break;
        case 4:
            case4(n_file);
            break;
        case 5:
        case5(n_file);
            break;
        case 6:
            case6(n_file,n_dir);
            break;    
        }

    } while (option != 7);
}
