#include<stdio.h>
int power(int base,int exp){
    int res=1;
    while(exp!=0){
        res*=base;
        exp--;
    }
    return res;
}
int main(){
    int base,exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    int result = power(base, exp);
    printf("%d raised to the power of %d is: %d\n", base, exp, result);
    return 0;
}