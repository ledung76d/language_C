#include<stdio.h>
#include<stdlib.h>

int change( char c) // doi ki tu char sang int
{
    return (int)c-48;
}

int main()
{
    char case3[4];
    int teleport;
    do
    {
        printf("\n Case 3: \n"
               "\n R - Right   "
               "\n L - Left"
               "\n U - Up"
               "\n D - Down"
               "\n\n0 - EXIT case 3\n\n");

        printf("Option: ");
        scanf("%s", case3);
        teleport=change(case3[0]);  
        printf("====== %d\n",teleport);      
       
        switch (teleport)
        {

        case 34:
            break;
        case 28:
            printf("Nhap kich thuoc tro choi NxN\n");
            break;
        case 37:
            printf("\nNhap du lieu tro choi\n");
            break;
        case 20:
            printf("\nNhap du lieu tro choi\n");
            break;    
        default:
            printf("\nINVALID OPTION!!!\n");
            break;
        }

    } while (teleport != 0);
   
}
