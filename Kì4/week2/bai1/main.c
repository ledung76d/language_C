#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void exch(void *a, size_t size, int i, int j)
{
    void *temp = malloc(size);
    memcpy(temp, (char *)a + i * size, size);
    memcpy((char *)a + i * size, (char *)a + j * size, size);
    memcpy((char *)a + j * size, temp, size);
}
int compare(void const *x, void const *y)
{
    int m, n;
    m = *((int *)x);
    n = *((int *)y);
    if (m == n)
        return 0;
    return m > n ? 1 : -1;
}
//sort2way
void sort2way(void* a, int l, int r, size_t size, int (*compare)(void const*, void const*)) {
    if(l >= r) return;
    int i = l, j = r;
    void* tmp = malloc(size);
    void* pivot = (char*)a + i * size;
    for(;;) {
        while(compare((char*)a + i * size, pivot) < 0) i++;
        while(compare(pivot, (char*)a + j * size) < 0) j--;
        if(i >= j) break;
        memcpy(tmp, (char*)a + i * size, size);
        memcpy((char*)a + i * size, (char*)a + j * size, size); 
        memcpy((char*)a + j * size, tmp, size);
        i++; j--;
    }
    free(tmp);
    sort2way(a, l, i-1, size, compare);
    sort2way(a, j+1, r, size, compare);
}
//sort3way
void sort(void *a, int size, int l, int r,
          int (*compare)(void const*, void const*))
{
    if (r <= l)
        return;
    int i = l - 1, j = r;
    int p = l - 1, q = r;
    while (1)
    {
        while (compare((char *)a + (++i) * size, (char *)a + r * size) < 0)
            ;
        while (compare((char *)a + r * size, (char *)a + (--j) * size) < 0)
            if (j == l)
                break;
        if (i >= j)
            break;
        exch(a, size, i, j);
        if (compare((char *)a + i * size, (char *)a + r * size) == 0)
            exch(a, size, ++p, i);
        if (compare((char *)a + j * size, (char *)a + r * size) == 0)
            exch(a, size, --q, j);
    }
    exch(a, size, i, r);
    j = i - 1;
    i = i + 1;
    for (int k = l; k <= p; k++)
        exch(a, size, k, j--);
    for (int k = r - 1; k >= q; k--)
        exch(a, size, k, i++);
    sort(a, size, l, j, compare);
    sort(a, size, i, r, compare);
}

//CreateArray
int *createArray(int size)
{
    int *Arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
    {
        Arr[i] = rand() % 10;
    }
    return Arr;
}
// Cpy arry
int *dumpArray(int *p, int size)
{
    int *Arr = malloc(sizeof(int) * size);

    memcpy(Arr, p, sizeof(int) * size);
    return Arr;
}
//Print Arr
int In_Arr(int *a, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

//
#define MAX 1000
int main()
{
    //
    srand((int)time(0));
    clock_t begin;
    clock_t end;
    double time_spent;
    //Tao Arr
    int *Arr = createArray(MAX);
    int *Arr1 = dumpArray(Arr, MAX);
    int *Arr2 = dumpArray(Arr, MAX);
    int size=sizeof(int);
    //run time
    //In_Arr(Arr1, MAX);
    begin = clock();
    //sort3way(Arr1,0,9,size,compare);
    sort(Arr1, size, 0, MAX-1,compare);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThoi gian thuc hien sort3way: %.10lf s", time_spent);
    //In_Arr(Arr1, MAX);
    
    //run time
    //In_Arr(Arr2, MAX);
    begin = clock();
    sort2way(Arr2,0,MAX-1,sizeof(int),compare);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThoi gian thuc hien sort2way: %.10lf s\n", time_spent);
    //In_Arr(Arr2, MAX);
    
    return 0;
}