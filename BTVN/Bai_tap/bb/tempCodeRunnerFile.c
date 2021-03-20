int f(int n){
    if (n<=0) return 1;
    if(n%2==1) return 2*f(n-1)+f(n-2);
    else return f(n-1)+3*f(n-2);  
}