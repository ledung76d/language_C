#include<stdio.h>
#include<string.h>

void clearBuffer()
{
     
    //fflush(stdin);
    
    //(clears the input buffer) 
    //while ((getchar()) != '\n'); 
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

}
// doi thoi gian 10:20 sang phut 
int convertMin(char time[6])
{
    // phut luon o 2 chu so  
    // 10:05, 2:00  
    // phut = (time[strlen(time)-2]-'0')*10 + (time[strlen(time)-1]-'0') 
    int ret = (time[strlen(time)-2]-'0')*10 + (time[strlen(time)-1]-'0');
    // gio bat dau tu time[strlen(time)-4)
    // neu 1 chu so 2:05  3:45 
    if(strlen(time)==4)
        ret= ret + (time[0]-'0')*60;
    else // 12:05 17:00
        ret= ret + (time[0]-'0')*60*10 + (time[1]-'0')*60;
        
    return ret;
}
//ham sap xep
void sapxep(int *a,int n)
{
	int i,j,tmp;
	tmp=0;
	for( i = 0;i < n;i++ )
	{
		for(j=i;j<n;j++)
		{
			if(a[j]<a[i])
			{
				tmp=a[j];
				a[j]=a[i];
				a[i]=tmp;	
			}
		}
	}
	

}

int main()
{
	//clearBuffer();
	//printf("%d",convertMin("12:20"));
	int i,a[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	sapxep(&a,5);
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	
	
	


}
