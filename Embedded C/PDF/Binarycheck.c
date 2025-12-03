#include<stdio.h>
int binary(int n){
    while(n>0){
        int rem=n % 10;
        if(rem != 0 && rem != 1) {
            return 0; 
        n /= 10;
        }
        return 1;
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%lu", &n);
    if(binary(n)){
        printf("The number is a binary number.\n");
    } else {
        printf("The number is not a binary number.\n");
    }
    return 0;
}