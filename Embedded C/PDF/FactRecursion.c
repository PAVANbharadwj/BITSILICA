#include<stdio.h>
int fact(int n){
    if(n<0) return -1;
    if(n==0 || n==1) return 1;
    else
    return n*fact(n-1);
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = fact(n);
    if(result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("The factorial of %d is: %d\n", n, result);
    }
    return 0;
}