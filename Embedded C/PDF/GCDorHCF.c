#include<stdio.h>
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd;
    while(b!=0){
        gcd = b;
        b = a % b;
        a = gcd;
    }
    printf("GCD of the two numbers is: %d\n", gcd);
    return 0;
}