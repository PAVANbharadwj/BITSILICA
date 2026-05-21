#include<stdio.h>
int rev(int n){
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}
int main(){
    int n;
    printf("Enetr a number:");
    scanf("%d",&n);
    rev(n);
    printf("Reversed Number: %d",rev(n));
    return 0;
}