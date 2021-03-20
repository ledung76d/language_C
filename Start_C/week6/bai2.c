#include<stdio.h>

int main()
{
	int country[20]={644089,165155,180659,147863,98476,76389,33573,134753,82341,28153,28912,69392,26336,11927,28379,18091,5136,5847,12547,12370};
	int tennuoc[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	//Sap xep 
	int i,j, k = 20, tmp,x;
  	int viTriMax;

	while (k > 1)
    {  
	    viTriMax = 0;
	    for (i = 1; i < k; i++)
		if (country[i] > country[viTriMax])
		viTriMax = i;
		
		x=tennuoc[viTriMax];
		tennuoc[viTriMax]=tennuoc[k-1];
		tennuoc[k-1]=x;
		
	    tmp = country[viTriMax];
	    country[viTriMax] = country[k - 1];
	    country[k - 1] = tmp;
	    
	    k = k - 1;
    }
	// top 5
	printf("Top 5 nuoc co ty le nhiem benh cao nhat:\n");
	for(i=19;i>=15;--i) 
	{	
		printf("Top %d: Nuoc thu %d - %d ca nhiem\n",20-i,tennuoc[i],country[i]);
	}
	
	// nho hon 100000;
	printf("\nCac quoc gia dang co so nguoi nhiem duoi 100000:\n");
	for(i=19;i>=0;--i)
	{
		if(country[i]>100000) continue;
		printf("Nuoc thu %d - %d ca nhiem\n",tennuoc[i],country[i]);	
	}
}
