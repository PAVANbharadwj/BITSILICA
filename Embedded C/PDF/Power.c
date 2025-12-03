#include<stdio.h>
#include<math.h>
int main(){
    int base,exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    double result = pow(base, exp);
    printf("%d raised to the power of %d is: %.0lf\n", base, exp, result);
    return 0;
}