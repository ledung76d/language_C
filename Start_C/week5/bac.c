int fibonacci(int n) {
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long c = 1;
    int i;
 
    if (n < 0) {
        return -1;
    } else if ( n == 1) {
        return n;
    } else {
        for (i = 2; i < n; i++) {
            a = b;
            b = c;
            c = a + b;
        }
    }
    return c;
}
 
/**
 * Ham main
 */
int main() {
 int i;
    printf("100 so dau tien cua day so Fibonacci: \n");
    for (i = 0; i < 100; i++) {
        printf("%d ", fibonacci(i));
    }
}
