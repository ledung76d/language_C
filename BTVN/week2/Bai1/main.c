#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct main
{
    
}Words;



void menu();



int main()
{
    menu();
}

void menu()
{
    
    int n;
    do
    {
        printf("Console  menu");
        /*
            1 là copy nhung từ mà có chữ m cho sẵn 
            2 là copy nhung từ mà ở trong dòng(?) 
            3 là copy có kích cỡ cho trước copy xong cho phần mềm in ra thời gian xử lí của 
            3 trường hợp chú ý là file nhập có kích cỡ lớn (>640kb)
        */
        printf("\n1. Copy words that contain given character");
        printf("\n2. Copy words that are in lines");
        printf("\n3. Copy words that are in arbitrary size block");
        printf("\n4.Exit");
        printf("\nNhap so:");
        scanf("%d",&n);
        
        switch (n)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        }
    } while (n!=4);
    
}


