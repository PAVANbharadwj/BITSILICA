#include<stdio.h>
int prime(int n){
    if(n<=1)return 0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0)return 0;
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(prime(n)){
        printf("The number is a prime number.\n");
    } else {
        printf("The number is not a prime number.\n");
    }
    return 0;
}