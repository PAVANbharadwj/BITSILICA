#include<stdio.h>
int power(int base, int exp) {
    int result = 1;
    while (exp != 0) {
        result *= base;
        exp--;
    }
    return result;
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int orginal=n;
    int res=0, count=0, rem=0;
    int temp = n;
    while(temp != 0){
        count++;
        temp /= 10;
    }
    temp = n;
    while(temp != 0){
        rem = temp % 10;
        res += power(rem, count);
        temp /= 10;
    }
    if(res == orginal){
        printf("The number is an Armstrong number.\n");
    } else {
        printf("The number is not an Armstrong number.\n");
    }
    return 0;
}