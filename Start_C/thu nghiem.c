#include<stdio.h>

int nhapso(int* a, int* b, int* c) {
scanf("%d%d%d", a, b, c);
return a,b,c;
}

int max(int a, int b) {
if(b>a) return b;
else return a;
}

int main() {
int a = 0, b = 0, c = 0,d;
nhapso(a,b,c);
d=max(b,c);
printf("%d", max(a,d));
}
