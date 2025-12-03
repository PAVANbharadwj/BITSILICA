#include <stdio.h>

int main() {
    int n;
    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);

    int fib[n];

    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci numbers at even indices:\n");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", fib[i]);
    }

    return 0;
}
