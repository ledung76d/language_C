#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
void insertionSort(elementtype arr[], int n)
{
    elementtype tmp;
    for(int i = 1; i < n; i++)
    {
        tmp = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > tmp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}
void selectionSort(elementtype arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minindex = i;
        for(int j = i + 1; j < n - 1; j++)
        {
             if(arr[minindex] > arr[j])
             {
                 minindex = j;
             }
        }
        int tmp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = tmp;
    }
}
//Heap Sort
void heapify(elementtype arr[], int i, int heapSize)
{
    int leftNode = 2 * i;
    int rightNode = 2 * i + 1;
    int largest;
    if(leftNode <= heapSize && arr[leftNode] > arr[i])
    {
        largest = leftNode;
    }
    else
    {
        largest = i;
    }
    if(arr[rightNode] > arr[largest] && rightNode <= heapSize)
    {
        largest = rightNode;
    }
    if(largest != i)
    {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, largest, heapSize);
    }
}
void creatHeap(elementtype arr[], int n)
{
    for(int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i, n - 1);
    }
}
void heapSort(elementtype arr[], int n)
{
    creatHeap(arr, n);
    int heapSize = n - 1;
    for(int i = heapSize; i >= 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[heapSize];
        arr[heapSize] = tmp;
        heapSize--;
        heapify(arr, 0, heapSize);
    }
}
void quickSort(elementtype arr[], int l, int r)
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
        quickSort(arr, i, r);
    }
    if(l < j)
    {
        quickSort(arr, l, i);
    }
}
int main()
{
    elementtype arr[10] = {1, 4, 2, 6, 3, 5, 7, 9, 8, 10};
    //insertionSort(arr, 10);
    //selectionSort(arr, 10);
    //heapSort(arr, 10);
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
