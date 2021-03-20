#include<conio.h>
#include<stdio.h>
#include<string.h>

main()
{
char hoten[100];
int toan[100],ly[100],anh[100],sohs,i;
float tb[100];

printf("Nhap so luong hoc sinh: ");scanf("%d",&sohs);
	for(i=1;i<=sohs;i++)
	{
	
	printf("\nHoc sinh so %d",i);
	fflush(stdin);
	printf("\nHo va ten: ");scanf("%c",&hoten[i]);
	fflush(stdin);
	printf("\nDiem Toan: ");scanf("%d",&toan[i]);
		if(0<=toan[i]<=10)
		{
		printf("\nDiem Ly: ");scanf("%d",&ly[i]);
			if(0<=ly[i]<=10)
			{
			printf("\nDiem Anh: ");scanf("%d",&anh[i]);
				if(0<=anh[i]<=10)
				{
				tb[i]=(2*toan[i]+ly[i]+anh[i])/4;
				}
				else
				{
				printf("\nNhap sai, 0<=diem<=10.\nNhap lai diem Anh: ");
				scanf("%d",&anh[i]);
				}
			}
			else
			{
			printf("\nNhap sai, 0<=diem<=10.\nNhap lai diem Ly: ");
			scanf("%d",&ly[i]);
			}
		}
		else
		{
		printf("\nNhap sai, 0<=diem<=10.\nNhap lai diem Toan: ");
		scanf("%d",&toan[i]);
		}
	}

printf("\nBam 1 nut bat ky de xem thong tin da nhap");
getch();
printf("\n\n\nHo va ten	Toan	Ly	Anh	TB");
	for(i=1;i<=sohs;i++)
	{
	printf("\n %c",hoten[i]);
	printf("		%d",toan[i]);
	printf("	%d",ly[i]);
	printf("	%d",anh[i]);
	printf("	%.2f",tb[i]);
	}

getch();
return(0);
}
