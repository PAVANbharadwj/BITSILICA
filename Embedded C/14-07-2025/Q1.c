#include<stdio.h>
int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }   
    return b;
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Fibonacci number at position %d is %d\n", n, fib(n));
    return 0;
}