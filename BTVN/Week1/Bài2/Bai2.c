#include <stdio.h>
#include <stdlib.h>

float luyThua(int n, int k) {
    int pow = 1;
    for (int i = 1; i <= k; i++)
        pow *= n;
    return (float)pow;
}
 
float giaiThua(int n) {
    int giaithua = 1;
    for (int i = 1; i <= n; i++)
        giaithua *= i;
    return (float)giaithua;
}
 
float fun(int x) {
    float sum = 0;
    int i = 0;
    while (luyThua(x, i) / giaiThua(i) > 1e-10 ) {
        sum += luyThua(x, i) / giaiThua(i);
        i++;
    }
    return sum;
}
 
int main() {
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("e^x: %6f", fun(x));
    return 0;
}
 
