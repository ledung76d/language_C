#include<stdio.h>

int main(){
    int arr[5][5] = {{1,0,1,0,1},
                     {1,0,1,0,1},
                     {1,0,1,0,1},
                     {1,0,1,0,1},
                     {1,0,1,0,1}};
int n=1;
int dem=n;
    /*
        In ra các số lẻ <= 10.
     */
 
    int number = 1;
    while (number <= 10){
        if(number % 2 == 1){
            printf("%d\t", number);
        }
        number++;
    }
}
 