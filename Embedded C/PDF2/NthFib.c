#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);

    int res = fib(n);
    printf("The %dth Fibonacci number is: %d\n", n, res);

    return 0;
}
