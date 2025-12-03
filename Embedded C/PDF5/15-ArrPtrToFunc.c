#include <stdio.h>

int add(int a, int b)       { return a + b; }
int subtract(int a, int b)  { return a - b; }
int multiply(int a, int b)  { return a * b; }
int divide(int a, int b)    { return b != 0 ? a / b : 0; }

int main() {
    int a = 20, b = 10;
    int (*fptr[])(int, int) = {add, subtract, multiply, divide};
    printf("Operations on %d and %d:\n", a, b);
    printf("1. Add: %d\n", fptr[0](a, b));
    printf("2. Subtract: %d\n", fptr[1](a, b));
    printf("3. Multiply: %d\n", fptr[2](a, b));
    printf("4. Divide: %d\n", fptr[3](a, b));
    return 0;
}
