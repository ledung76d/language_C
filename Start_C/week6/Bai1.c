#include <stdio.h>
#include <math.h>
int main()
{
    int week[7];
    int i;
    
    printf("Nhap thoi gian hoc cua tung ngay trong tuan:\n");
    for(i=0; i<7;i++)
    {
        printf("Week %d: ",i+1);
        scanf("%d", &week[i]);
    }
    // tinh trung binh thoi gian va in rta 
    int tongthoigian=0;
    for(i=0;i<7;i++) tongthoigian=tongthoigian+week[i];
    double trungbinh;
    	trungbinh=(1.0*tongthoigian)/7;
    printf("Tong thoi gian hoc: %d phut\n",tongthoigian);
    printf("Thoi gian hoc trung binh 1 tuan: %.2lf phut\n",trungbinh);
    
    // nhung ngay co thoi gian hoc nhieu hon gia tri trung binh
    printf("\nNhung ngay co thoi gian hoc nhieu :\n");
	for(i=0;i<7;i++)
    {
    	if(week[i]>trungbinh) printf("Ngay %d co thoi gian hoc %d phut\n",i+1,week[i]);
	}
	
	//Bieu do
	int max_week=week[0];
	for(i=1;i<7;i++)
	{
		if(week[i]>max_week) 
			max_week=week[i];
	}
	
	int max_cot=80,j;
	printf("Bieu do theo tuan:\n");
	for(i=0;i<7;i++)
	{
		printf("Week %d ",i+1);
		int sodausao ;
			
			sodausao= round((float)week[i]*max_cot/max_week); // lam tron 3.5-->4,  3.2 -->3
        for(j=0; j<sodausao; j++) printf("*");
        printf("\n");

	}
}
