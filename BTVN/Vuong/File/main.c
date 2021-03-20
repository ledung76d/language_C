#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Đọc file không có cấu trúc
    FILE *fp = fopen("filename.txt","r");
    char a[100];
    if(fp != NULL)
    {
        while(fgets(a, 100, fp) != NULL)
        {
            printf("%s", a);
        }
    }
    else
    {
        printf("Co loi khi mo file!\n");
    }
    fclose(fp);
    // Đọc file có cấu trúc kiểu chia làm nhiều cột
    printf("\n\n\n");
    FILE *fp1 = fopen("filename1.txt", "r");
    char name[100];
    char matdanh[100];
    char v[100];
    if(fp1 != NULL)
    {
        printf("%-50s%-50s%-50s\n", "Ten", "Mat danh", "Deo biet viet gi");
        while(fscanf(fp1,"%s%s%s", name, matdanh, v) != EOF)
        {
            printf("%-50s%-50s%-50s", name, matdanh, v);
            printf("\n");
        }
    }
    else
    {
        printf("Co loi khi mo file!\n");
    }
    fclose(fp1);
    //Coppy file (Dựa vào để làm bài sửa lại file)
    FILE *fp2 = fopen("filename1.txt", "r");
    FILE *fp3 = fopen("filename2.txt", "w");
    if(fp2 != NULL)
    {
        //printf("%-50s%-50s%-50s\n", "Ten", "Mat danh", "Deo biet viet gi");
        while(fscanf(fp2,"%s%s%s", name, matdanh, v) != EOF)
        {
            //printf("%-50s%-50s%-50s", name, matdanh, v);
            //printf("\n");
            fprintf(fp3,"%-50s%-50s%-50s\n", name, matdanh, v);
        }
    }
    else
    {
        printf("Co loi khi mo file!\n");
    }
    fclose(fp2);
    fclose(fp3);
    //Viết tiếp vào cuối file
    FILE *fp4 = fopen("filename3.txt", "a+");
    if(fp4 != NULL)
    {
        fprintf(fp4,"Noi dung them\n");
    }
    else
    {
        printf("Co loi khi mo file!\n");
    }
    return 0;
}
