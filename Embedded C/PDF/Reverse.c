#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int rem=0;
    int rev=0;
    while(n>0){
        rem = n % 10;          
        rev = rev * 10 + rem;
        n = n / 10;
    }
    printf("Reversed number is: %d\n", rev);
    return 0;
}