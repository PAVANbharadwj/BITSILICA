#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int temp=n;
    int rem=0,rev=0;
    while(n>0){
        rem= n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    if(temp == rev){
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
}