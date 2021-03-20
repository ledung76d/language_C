#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* createArray(int size) {
    int* arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    return arr;
}

int* dumpArray(int* p, int size) {
    int* arr = malloc(sizeof(int) * size);
    //for (int i = 0; i < size; ++i) { arr[i] = p[i]; }
    memcpy(arr, p, sizeof(int) * size);
    return arr;
}

void sort2way(void* a, int l, int r, size_t size, int (compare)(void const*, void const*)) {
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
    sort2way(a, l, i-1, size, compare);
    sort2way(a, j+1, r, size, compare);
}

void exch(void* a, int i, int j, size_t size) {
    void* temp = malloc(size);
    memcpy(temp, (char*)a + i * size, size);
    memcpy((char*)a + i * size, (char*)a + j * size, size); 
    memcpy((char*)a + j * size, temp, size);
}

void sort3way(void* a, int l, int r, size_t size, int (compare)(void const*, void const*)) {
    if (r <= l) return;
    int i = l-1, j = r;
    int p = l-1, q = r;
    while(1) {
        while (compare((char*)a + (++i) * size, (char*)a + r * size) < 0);
        while (compare((char*)a + r * size, (char*)a + (--j) * size) < 0) if (j == l) break;
        if (i >= j) break;
        exch(a, i, j, size);
        if (compare((char*)a + i * size, (char*)a + r * size) == 0) exch(a, ++p, i, size);
        if (compare((char*)a + j * size, (char*)a + r * size) == 0) exch(a, --q, j, size);
    }
    exch(a, i, r, size);
    j = i - 1;
    i = i + 1;
    for (int k = l ; k <= p; k++) exch(a, k, j--, size);
    for (int k = r-1; k >= q; k--) exch(a, k, i++, size);
    sort3way(a, l, j, size, compare);
    sort3way(a, i, r, size, compare);
}

int is_sorted(int input_array[], int size_of_array){
	int i ;
	for(i = 0; i < size_of_array - 1; i ++){
		if(input_array[i] > input_array[i+1]){
			return -1;
		}
	}
	return 1;
}

void printArray(FILE* f ,int* a, int size) {
    printf("\n");
    for(int i = 0; i < size; ++i) {
        fprintf(f, "%d ", a[i]);
    }
   
}

int int_compare(void const* x, void const* y) {
    int m, n;
    m = ((int)x);
    n = ((int)y);
    if(m == n) return 0;
    return m > n ? 1 : -1;
}

int main() {
    FILE* output2 = fopen("output2way.txt", "w"); 
    FILE* output3 = fopen("output3way.txt", "w");
    
    int* smallArray = createArray(10);
    
    printArray(stdout, smallArray, 10);

    int* dump2 = dumpArray(smallArray, 10);
    printf("Sort 2-way: \n"); sort2way(dump2, 0, 9, sizeof(int), int_compare);
    printArray(stdout, dump2, 10);
    free(dump2);

    int* dump3 = dumpArray(smallArray, 10);
    printf("Sort 3-way: \n"); sort3way(dump3, 0, 9, sizeof(int), int_compare);
    printArray(stdout, dump3, 10);
    free(dump3);
    
    int* bigArray = createArray(1000);
    clock_t begin = clock();
    dump2 = dumpArray(bigArray, 1000);
    sort2way(dump2, 0, 1000 - 1, sizeof(int), int_compare);
    //printArray(output2, dump2, 10000000);
    free(dump2);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Sort 2-way: %lf\n", time_spent); 

    begin = clock();
    dump3 = dumpArray(bigArray, 1000);
    sort3way(dump3, 0, 1000 - 1, sizeof(int), int_compare);
    //printArray(output3, dump3, 10000000);
    free(dump3);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Sort 3-way: %lf\n", time_spent); 
}