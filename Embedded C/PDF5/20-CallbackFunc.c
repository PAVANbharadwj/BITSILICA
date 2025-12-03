#include <stdio.h>
int square(int x) {
    return x * x;
}
void compute(int num, int (*callback)(int)) {
    int result = callback(num);  
    printf("Square of %d is %d\n", num, result);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    compute(n, square);
    return 0;
}
