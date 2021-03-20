#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int random1(int minN, int maxN);
int random2();
int *createArray(int size);
int * dumpArray(int *p, int size);
//void memcpy(void* dest, void* src, size_t size);
void sort2way(int a[], int l, int r); //Error
void sort3way(int a[], int l, int r);
void exch(int a[],int i, int j);
void inArr(int a[],int size);
//sort2way2
void swap(int *a, int *b);
int partition (int arr[], int low, int high);
void sort2way2(int arr[], int low, int high);
#define MAX 10000000
#define MIN 10000000
int main(){  
    srand((int)time(0));
    clock_t begin;
    clock_t end;
    double time_spent;
    
    //Tao du lieu
    srand((int)time(0));
   
    int *a1=createArray(MIN);
    printf("Ban dau\n");
    //inArr(a1,MIN);
    int *a2=dumpArray(a1,MIN);
    //inArr(a2,MIN);
    //Sapxep    
    printf("\nSau sx: \n");
    
    begin = clock();
    sort3way(a1,0,MIN);
    //inArr(a1,MIN);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc hien 3waysort: %.10lf s\n\n", time_spent);

    //
    begin = clock();
    sort2way2(a2,0,MIN);
    //inArr(a2,MIN);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc hien quicksort: %.10lf s\n\n", time_spent);
    

}
void inArr(int a[],int size){
    for(int i=0;i<size;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void exch(int a[],int i, int j){
    int tmp;
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}

int random1(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
int random2(){
    srand((int)time(0));
    int r;
    r = random1(1,10);
    return r;
}
void inputdata(int size,int Arr[]){
     for(int i=0;i<size;++i){
        Arr[i]=random1(1,10);
    }
}
int *createArray(int size){
    int *Arr;
    Arr = (int*) malloc(size * sizeof(int));
    inputdata(size,Arr);
    return Arr;
}
int * dumpArray(int *p, int size){
    int *b;
    b = (int*) malloc(size * sizeof(int));
    for(int i=0;i<size;++i){
        *(b+i)=*(p+i);
    }
    return b;
}



void sort3way(int a[], int l, int r) {
	if (r <= l) return;
	int i = l-1, j = r;
	int p = l-1, q = r;
	while(1)	{
		while (a[++i] < a[r]);
		while (a[r] < a[--j]) if (j == l) break;
		if (i >= j) break;
		exch(a, i, j);
		if (a[i]==a[r]) exch(a, ++p, i);
		if (a[j]==a[r]) exch(a, --q, j);
	}
	exch(a, i, r);
	j = i - 1;
	i = i + 1;
	for (int k = l ; k <= p; k++) exch(a, k, j--);
	for (int k = r-1; k >= q; k--) exch(a, k, i++);
	sort3way(a, l, j);
	sort3way(a, i, r);
}


//sort2way2
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(1){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}
 
/* Hàm thực hiện giải thuật quick sort */
void sort2way2(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        sort2way2(arr, low, pi - 1);
        sort2way2(arr, pi + 1, high);
    }
}

void sort2way(int arr[], int l, int r)
{
    int i = l, j = r;
    int p = arr[(l + r) / 2];
    while(i < j)
    {
        while(arr[i] < p)
        {
            i++;
        }
        while(arr[j] > p)
        {
            j--;
        }
        if(i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(i < r)
    {
        sort2way(arr, i, r);
    }
    if(l < j)
    {
        sort2way(arr, l, i);
    }
}