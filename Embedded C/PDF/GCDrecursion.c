#include<stdio.h>
int recursiveGCD(int a, int b) {
    if (b == 0) return a;
    return recursiveGCD(b, a % b);
}
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd = recursiveGCD(a, b);
    printf("GCD of the two numbers is: %d\n", gcd);
    return 0;
}