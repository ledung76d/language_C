#include <stdio.h>
void clearBuffer()
{
     
    // fflush(stdin);
    
    // (clears the input buffer) 
    // while ((getchar()) != '\n'); 
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

}

int main(){
    for (int i=0;i<10;i++){
        printf("%d",i);
    }
}
