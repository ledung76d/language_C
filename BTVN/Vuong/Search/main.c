#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
int binSearch(elementtype arr[], int n, elementtype value)
{
    int l = 0, r = n - 1;
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(arr[mid] == value)
        {
            return mid;
        }
        else if(arr[mid] > value)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binSearch(arr, 10, 5));
    printf("%d\n", binSearch(arr, 10, -4));
    return 0;
}
