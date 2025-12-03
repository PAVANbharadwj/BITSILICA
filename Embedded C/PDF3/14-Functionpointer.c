#include <stdio.h>
void compute(int a, int b, int *sum, int *product) {
    *sum = a + b;
    *product = a * b;
}

int main() {
    int x, y, s, p;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    compute(x, y, &s, &p); 
    printf("Sum = %d\n", s);
    printf("Product = %d\n", p);

    return 0;
}
