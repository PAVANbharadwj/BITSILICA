#include<stdio.h>
int SumOfDigits(int n){
    if(n<=0) return 0;
    else return n % 10 + SumOfDigits(n / 10);
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int sum = SumOfDigits(n);
    printf("Sum of digits is: %d\n", sum);
    return 0;
}