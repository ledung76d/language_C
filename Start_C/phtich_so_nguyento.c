#include <stdio.h>
 
int main(){
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    int dem,i;
    printf("\n%d = ",n);
    for(i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n=n/i;
        }      
        
            if(dem > 1) printf("%d^%d", i, dem);
            else printf("%d", i);
            if(n > i){
                printf(" x ");
            
        }
    }
    
}
