#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist STACK;

STACK *push( STACK * p,int value){
    STACK *temp;
    temp=(STACK *)malloc(sizeof(STACK));
    if(temp==NULL){
        printf("No memory available Error\n");
        exit(0);
    }
    temp->data=value;
    temp->next=p;
    p=temp;
    return p;
}

STACK *pop(STACK *p, int *value){
    STACK *temp;
    if(p==NULL){
        printf("The stack is empty can not pop Error\n");
        exit(0);
    }
    *value=p->data;
    temp=p;
    p=p->next;
    free(temp);
    return p;
}


void input_Game(int **a, int n, int *adress_x, int *adress_y);
void in_sao(int length);
void level_game(int n); //n so hang so cot NxN
void print_Game(int **a, int hang, int cot);
//Chuc nang game
int change( char c);
int swap_right(int **a, int *adress_x, int *adress_y ,int n);
int swap_left(int **a, int *adress_x, int *adress_y ,int n);
int swap_up  (int **a, int *adress_x, int *adress_y,int n );
int swap_down(int **a, int *adress_x, int *adress_y,int n );

int main()
{
    int option = 0;
    int i, j;
    int n = 0;
    int adress_x = 0; //vi tri hang
    int adress_y = 0; //vi tri cot
    STACK *temp=NULL; // Ngan xep luu du case 3
    int value1=0; //Dem so luong phan tu ngan xep

    do
    {
        printf("\n Menu \n"
               "\n1 -   Level-Chon muc choi   "
               "\n2 -   Nhap du lieu"
               "\n3 -   Start"
               "\n4 -   Rollback "
               "\n5 -   In game "
               "\n\n0 - EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {

        case 0:

            break;

        case 1:
            printf("Nhap kich thuoc tro choi NxN\n");
            do
            {
                printf(" 3<=N<=7 : ");
                scanf("%d", &n);
            } while (n > 7 || n < 3);
            int **a = NULL;
            // Cấp phát mảng các con trỏ cấp 1
            a = (int **)malloc(n * sizeof(int *)); //n so thu tu hang
            for (i = 0; i < n; i++)
            {
                // Cấp phát cho từng con trỏ cấp 1
                a[i] = (int *)malloc(n * sizeof(int)); //n so thu tu cot
            }

            printf("\n==========================\n");
            break;

        case 2:
            printf("\nNhap du lieu tro choi\n");
            if (n == 0)
            {
                printf("Ban chua chon level choi.\n");
                printf("De nghi chon 1 \n");
                break;
            }
            input_Game(a, n, &adress_x, &adress_y);
            break;

        case 3:
            printf(" ======Start====== \n");
            
                char case3[4];
                int teleport;
                // Chuc nang di chuyen
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
                    teleport = change(case3[0]);
                    printf("====== %d\n", teleport);

                    switch (teleport)
                    {

                    case 0:
                        break;
                    case 34: // sang phai
                        value1++;
                        temp=push(temp,34);
                        swap_right(a,&adress_x,&adress_y ,n);
                        print_Game(a,n,n);
                        break;    
                    case 28: // sang trai
                        value1++;
                        temp=push(temp,28);
                        swap_left(a,&adress_x,&adress_y ,n);
                        print_Game(a,n,n);
                        break;
                    case 37: // len
                        value1++;
                        temp=push(temp,37);
                        swap_up(a,&adress_x,&adress_y ,n);
                        print_Game(a,n,n);
                        break;
                    case 20: //xuong
                        value1++;
                        temp=push(temp,20);
                        swap_down(a,&adress_x,&adress_y ,n);
                        print_Game(a,n,n);
                        break;
                    default:
                        printf("\nINVALID OPTION!!!\n");
                        break;
                    }

                } while (teleport != 0);
            break;

        case 4:
            printf(" =====Rollback===== ");
            int number,value2;
            printf("\nNumber rollback: ");
            scanf("%d",&number);
            if (number<0||number>value1)
            {
                printf("Error Rollback?");
            }
            else
            {
                for(i = 0 ;i < number;i++ )
                {
                    temp=pop(temp,&value2);
                    switch (value2){
                        case 0:
                            break;
                        case 28: // sang phai                            
                            swap_right(a,&adress_x,&adress_y ,n);
                            break;    
                        case 34: // sang trai
                            swap_left(a,&adress_x,&adress_y ,n);
                            break;
                        case 20: // len
                            swap_up(a,&adress_x,&adress_y ,n);
                            break;
                        case 37: //xuong
                            swap_down(a,&adress_x,&adress_y ,n);
                            break;
                        default:
                            printf("\nINVALID OPTION!!!\n");
                            break;
                    } 
                }
                print_Game(a,n,n);
            }
            break;
        case 5:
            printf(" In cau hinh game\n");
            print_Game(a, n, n);
            break;
        default:
            printf("\nINVALID OPTION!!!\n");
            break;
        }

    } while (option != 0);
}

// Funtion
//nhap du lieu1
void level_game(int n) //n so hang so cot NxN
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("*a[%d][%d]", i, j);
        }
        printf("*\n");
    }
}
//nhap du lieu2
void input_Game(int **a, int n, int *adress_x, int *adress_y)
{
    int i, j;
    level_game(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
            {
                *adress_x = i; //so thu tu hang
                *adress_y = j; //so thu tu cot
            }
        }
    }
}
// in ***************
void in_sao(int length)
{
    for (int i = 0; i < length + 4; i++)
    {
        printf("*");
    }
    printf("\n");
}
// xuat ra man hinh
void print_Game(int **a, int hang, int cot)
{
    int i, j;
    in_sao(hang);
    for (i = 0; i < hang; i++)
    {
        for (j = 0; j < cot; j++)
        {
            printf("*%d", a[i][j]);
        }
        printf("*\n");
    }
    in_sao(hang);
}

//Chuc nang phan 3
int swap_right(int **a, int *adress_x, int *adress_y ,int n){
    int i=*adress_x;
    int j=*adress_y;
    int temp;
    if (*adress_y==n-1)
    {
        printf("Error right?\n");
        return 0;
    }else
    {
        temp=a[i][j];
        a[i][j]=a[i][j+1];
        a[i][j+1]=temp;
        *adress_y=j+1;
    } 
    return 1;
}
int swap_left(int **a, int *adress_x, int *adress_y ,int n){
    int i=*adress_x;
    int j=*adress_y;
    int temp;
    if (*adress_y==0)
    {
        printf("Error left?\n");
        return 0;
    }else
    {
        temp=a[i][j];
        a[i][j]=a[i][j-1];
        a[i][j-1]=temp;
        *adress_y=j-1;
    } 
    return 1;
}
int swap_up(int **a, int *adress_x, int *adress_y ,int n){
    int i=*adress_x;
    int j=*adress_y;
    int temp;
    if (*adress_x==0)
    {
        printf("Error up?\n");
        return 0;
    }else
    {
        temp=a[i][j];
        a[i][j]=a[i-1][j];
        a[i-1][j]=temp;
        *adress_x=i-1;
    } 
    return 1;
}
int swap_down(int **a, int *adress_x, int *adress_y ,int n){
    int i=*adress_x;
    int j=*adress_y;
    int temp;
    if (*adress_x==n-1)
    {
        printf("Error up?\n");
        return 0;
    }else
    {
        temp=a[i][j];
        a[i][j]=a[i+1][j];
        a[i+1][j]=temp;
        *adress_x=i+1;
    } 
    return 1;
}

int change( char c) // doi ki tu char sang int
{
    return (int)c-48;
}

