#include<stdio.h>
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main(){
    int n;
    printf("Enter sum of 2 primes: ");
    scanf("%d",&n);
    int found = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d (Both are prime)\n", n, i, n - i);
            found = 1;
        }
    }
    if (!found)
        printf("%d cannot be expressed as the sum of two prime numbers.\n", n);
    return 0;
}