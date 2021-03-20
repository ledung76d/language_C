#include<stdio.h>
int main(){
	int f0 = 0;
    int f1 = 1;
    int fn = 1;
    int i;
    printf(" 1 ");
	for (i = 2; i < 100; i++) {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
            if(fn>100) break;
            printf("%d ",fn);
        }
}
