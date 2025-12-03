#include<stdio.h>
int main(){
    int n,fact=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        fact+= n*n-1;
    }
    printf("The factorial of %d is: %d\n", n, fact);
    return 0;
}