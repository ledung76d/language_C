#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//include"timing.h"

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
// Ham printf
void Print_Array(int Arr[],int n){
    int i;
    printf("\nDanh sach mang");
    for(i=0;i<n;i++){
        printf("%d ",Arr[i]);
    }
}
// Ham sap xep chen
void Insertion_sort(int Arr[],int n)
{
    int i,j,tmp;
    for(i=1;i<n;i++)
    {
        tmp=Arr[i];
        j=i-1;

        while(j>=0 && Arr[j]>tmp)
        {
            Arr[j+1]=Arr[j];
            j=j-1;
        }
        Arr[j+1]=tmp;
    }
    Print_Array(Arr,n);
}

// Ham sap xep o menu 3
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void Selection_sort(int Arr[],int n)
{
    int i,j,address_min;
    for(i=0;i<n;i++)
    {
        address_min=i;
        for(j=i+1;j<n;j++)
        {
            if(Arr[j]<Arr[address_min])
            address_min=j;
        }
        swap(&Arr[i],&Arr[address_min]);
    }
    Print_Array(Arr,n);
}
//Sap xep head sort case 5
void rebuild(int v[], int limit, int pos)
{		
	int c1, c2;
	
	c1 = 2 * pos;
	c2 = c1 + 1;
	
	if(c1 > limit || (v[pos - 1] >= v[c1 - 1] && v[pos - 1] >= v[c2 - 1]))
		return;
	
	int greater_index = -1;
	
	if(c2 > limit)
		greater_index = c1;
	else
	{		
		if(v[c1 - 1] > v[c2 - 1])
			greater_index = c1;
		else
			greater_index = c2;
	}
	
	if(greater_index != -1)
	{
		int aux = v[greater_index - 1];
		v[greater_index - 1] = v[pos - 1];
		v[pos - 1] = aux;
		rebuild(v, limit, greater_index);
	}
}


void build(int v[], int size_v)
{
	int left;
	
	if(size_v % 2 == 0)
		left = size_v / 2 + 1;
	else
		left = (size_v - 1) / 2 + 1;
	
	while(left > 1)
	{
		left--;
		rebuild(v, size_v, left);
	}
}

void heap_sort(int v[], int size_v)
{
	// builds the heap
	build(v, size_v);

	/*
		change the item of the position 1 with the item of the position "n", 
		after with "n - 1", "n - 2" until there only 1 item.
	*/
	int limit = size_v;
	
	while(1)
	{		
		int aux = v[0];
		v[0] = v[limit - 1];
		v[limit - 1] = aux;
		
		rebuild(v, limit - 1, 1);
			
		limit--;
		
		if(limit <= 2 && v[0] <= v[1])
			break;
	}
}
int main()
{
    int *Arr;
    int n=10;
    double wc1 = 0, wc2 = 0, cpuT = 0;
    Arr=(int *)malloc(n * sizeof(int));
    srand((int)time(0));
    int option=1;
    do{
        printf("  \n\n  ==================");
        printf("  \n  =======MENU=======");
        printf( "\n1. Re-generate data  "
                "\n2. Insertion sort    "
                "\n3. Selection sort    "
                "\n4. Bubble sort       " 
                "\n5. Heap              "  
                "\n6. Printf            "
                "\n0. EXIT              ");
        printf( "\nOption: ");
        scanf("%d",&option);
        printf(" \n  ==================\n\n");
        switch (option)
        {
            case 0:
                break;
            case 1:
                for (int i = 0; i < n; ++i)
                {
                    Arr[i] = random(0, 2000000);
                }
                break;
            case 2:
                
                printf("Chuc nang 2");
                Insertion_sort(Arr,n);
                
                break;
            case 3:
                printf("Chuc nang 3");
                Selection_sort(Arr,n);
                break;
            case 4:
                /* code */
                break; 
            case 5:
                printf("Chuc nang 4");
                heap_sort(Arr,n);
                break;  
            case 6:
                Print_Array(Arr,n);
                break;
            default:
                break;
        }

    }while(option!=0);
}