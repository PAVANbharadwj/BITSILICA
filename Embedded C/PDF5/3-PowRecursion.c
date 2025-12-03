#include <stdio.h>

int power(int x, int n){
    if(n==0) return 1;
    return x*power(x,n-1);
}

int main() {
    int base, exponent;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exponent);

    int result = power(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}
