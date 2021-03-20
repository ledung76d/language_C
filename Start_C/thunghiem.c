#include <stdio.h> 
#include <string.h> 

int nhapso(int* a, int* b, int* c) {
scanf("%d%d%d", &a, &b, &c);
}

int max(int a, int b) {
if(b>a) return b;
else return a;
}

int main() {
int a = 0, b = 0, c = 0;
nhapso(a,b,c);
printf("%d", max(a,max(b,c)));
}
