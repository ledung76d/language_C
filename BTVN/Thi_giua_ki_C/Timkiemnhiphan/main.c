#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

struct Nguoi
{
    char MS[11];
    char Name[31];
    double diem;
};
typedef struct Nguoi SVien;

SVien SV[100];

void Ghi_file(){
    FILE *fp;
  
    fp=fopen("vanban.txt","w");
    if(fp==NULL){
        printf("<Error file>");
       exit(1);
    }
    int count=0;
    char c[6];
    //Nhap du lieu vo file
    char sentence[1000];
    char sentence2[100];
    printf("Entera sentence:\n");
    while(1){
        printf("Name : ");
        scanf("%s",sentence);
        if(strcmp(sentence, "===")==0) break;
        fprintf(fp,"%s   ",sentence);
        
        //clearBuffer();
        //fprintf(fp,"%s   ",sentence);
        printf("MSSV: ");
        scanf("%s",sentence2);
        //gets(sentence2);
        
        //clearBuffer();
        fprintf(fp,"%s   ",sentence2);
        
        printf("Diem[0,10]: ");
        do{
            scanf("%d",&count);
        }while(count<0&&count>10);
        
        //clearBuffer();
        fprintf(fp,"%d\n",count);

    }
       
    printf("Da nhap thanh cong!");
    fclose(fp);
}

void Doc_file(int *soLuong){
    FILE * fp;
    fp=fopen("vanban.txt","r");
    if(fp==NULL){
        printf("<Error file>");
       exit(1);
    }
    int dem=0;
    while(fscanf(fp,"%s   %s   %lf\n",SV[dem].Name,SV[dem].MS,&SV[dem].diem)!=EOF){
        dem++;
    }
    *soLuong=dem+1;
    fclose(fp);
}
int find( int n, char x[])
{
  int i;
  for (i = 0; i < n; i++)
    if (strcmp(SV[i].MS, x)==0)
      // Trả về chỉ số khi tìm thấy
      return i;
  // Nếu không tìm thấy trả về -1. Vì chỉ số mảng >= 0
  return -1;
}

int find1( int l, int r, char x[]) {
  if (r >= l) {
    int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn
 
    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (strcmp(SV[mid].MS, x)==0)
      return mid;
 
    // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    if (strcmp(SV[mid].MS, x)>0)
      return find1( l, mid - 1, x);
 
    // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
    return find1( mid + 1, r, x);
  }
 
  // Nếu không tìm thấy
  return -1;
}
 

int find_enter(int value){
    printf("MS: ");
    char c[10];
    scanf("%s",c);
    //int k=find(value,c);
    int m=0;
    int k=find1(m,value,c);
    if(k!=-1)    printf("%-10s %-10s %-10lf\n",SV[k].Name,SV[k].MS,SV[k].diem);
}
int main (){
    int option = 0;
    SVien tmp;
    int n;
    do
    {
        printf("\n Menu \n"
               "\n1 -   Tao file....   "
               "\n2 -   ...."
               "\n3 -   ...."
               "\n4 -   ...."
               "\n0 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            //Ghi_file();
            break;
        case 2:
            printf("Chuc nang 2\n");
            //Doc_file(&n);
            FILE *fp;
            fp = fopen("vanban.txt", "r");
            if (fp == NULL)
            {
                printf("<Error file>");
                exit(1);
            }
            int dem = 0;
            while (fscanf(fp, "%s   %s   %lf\n", SV[dem].Name, SV[dem].MS, &SV[dem].diem) != EOF)
            {
                printf("%s   %s   %lf\n", SV[dem].Name, SV[dem].MS, SV[dem].diem);
                dem++;
            }
            n= dem ;
            printf("%d\n",n);
            fclose(fp);
            break;
        case 3:
            printf("Chuc nang 3: \n");
            printf("%d\n",n);
        
            for (int i = 0; i < n ; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    
                    if (strcmp(SV[i].MS,SV[j].MS)>0)
                    {
                        //Hoan vi 2 so a[i] va a[j]
                        strcpy(tmp.MS ,SV[i].MS);
                        strcpy(SV[i].MS ,SV[j].MS);
                        strcpy(SV[j].MS ,tmp.MS);

                        strcpy(tmp.Name ,SV[i].Name);
                        strcpy(SV[i].Name ,SV[j].Name);
                        strcpy(SV[j].Name ,tmp.Name);
                        
                        tmp.diem =SV[i].diem;
                        SV[i].diem =SV[j].diem;
                        SV[j].diem =tmp.diem;
                    }
                }
            }
            printf("Danh sach: \n");
            for(int i=0;i<n;i++){
                printf("%-10s %-10s %-10lf\n",SV[i].Name,SV[i].MS,SV[i].diem);
            }
            for(int i=0;i<n;i++){

            }
            break;
        case 4:
            find_enter(n);
            break;
        case 5:
            break;
            
        }

    } while (option != 0);
}