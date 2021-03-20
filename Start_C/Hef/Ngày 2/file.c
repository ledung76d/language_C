#include<stdio.h>
#include<string.h>
struct timelog
{
	int ngay;
	char start[6];
	char end[6];
	int thoigian;
};
struct MonthLog
{
    struct timelog mLog[200];
    int size; // so luong ban ghi thuc su
    
    int dailyusage[31]; // thoi gian su dung hang ngay theo phut (bo phan tu 0)
    float dailyAvg, maxtime, mintime;
};
struct MonthLog Month;

void clearBuffer()
{   
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int swaptime(char time[]){

	int minute=0 ;
	if(strlen(time)==4){ 
		minute=(time[0]-'0')*60;
		minute=minute+(time[strlen(time)-2]-'0')*10+time[strlen(time)-1]-'0';
	}
	else{
		minute=((time[0]-'0')*10+(time[1]-'0'))*60;
		minute=minute+(time[strlen(time)-2]-'0')*10+time[strlen(time)-1]-'0';
	}
	return minute;
}

void inputdata(){
		printf("So luong ban ghi: ");
		scanf("%d",&Month.size);
		int i;
		for(i=0;i<Month.size;i++){
			printf("Ngay: ");
			scanf("%d",&Month.mLog[i].ngay);
			printf("Time start: ");
			scanf("%s",Month.mLog[i].start);
			printf("Time end: ");
			scanf("%s",Month.mLog[i].end);
			
			Month.mLog[i].thoigian=swaptime(Month.mLog[i].end)-swaptime(Month.mLog[i].start);
		}

}

void CalTotalTimeDaily()
{
    // fill mang dailyusage[31]
    int i;
	for(i=0;i<=31;i++){
		Month.dailyusage[i]=0;
	}

	
	int j;
    for(i=0;i<Month.size;i++)
	{
		for(j=1;j<=31;j++){
			if(Month.mLog[i].ngay==j) 
			Month.dailyusage[j]=Month.dailyusage[j]+Month.mLog[i].thoigian;
		}		
	}    

	for(i=1;i<=31;i++){
		printf("\nNgay %d: %d",i,Month.dailyusage[i]);
	}
	
    
    // tinh avgTime, max,min tu mang dailyusage[31]
    float sum;
    Month.dailyAvg=0;
    Month.maxtime=0; // tim max
   	Month.mintime=0; // tim min
    for(i=1;i<=31;i++){
		sum=(1.0*Month.dailyusage[i])+sum;
	}
	Month.dailyAvg=(1.0*sum)/31;
	int maxday,minday;
	float max=0,min=0;
	for(i=1;i<=31;i++){
		if(max<Month.dailyusage[i]){
			max=Month.dailyusage[i];	
			maxday=i;
		}
		
	}
		for(i=1;i<=31;i++){		
		if(min>Month.dailyusage[i]){
			min=Month.dailyusage[i];	
			minday=i;
		}
	}
	
	
	
	Month.mintime=min;
	Month.maxtime=max;
	printf(" \nTime Avg: %.2f",Month.dailyAvg);
	printf(" \nTime max: %.0f - Ngay %d",Month.maxtime,maxday);
	printf(" \nTime min: %.0f - Ngay %d",Month.mintime,minday);
	
		for(i=1;i<=31;i++){
		printf("\nNgay %d: %d",i,Month.dailyusage[i]);
	}
	
}

void outputdata(){
	inputdata();
	CalTotalTimeDaily();
	
}



int main(){
	outputdata();
}
