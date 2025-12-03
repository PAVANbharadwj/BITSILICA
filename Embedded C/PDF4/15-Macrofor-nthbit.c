#include <stdio.h>

#define TOGGLE_BIT(num, n) ((num) ^ (1 << (n)))

int main() {
    int num;
    printf("enter n value: ");
    scanf("%d",&num);
    int n;
    printf("Enter bit to toogle: ");
    scanf("%d",&n);
    int result = TOGGLE_BIT(num, n);
    printf("Original : %d (Binary: 1010)\n", num);
    printf("After toggling %d-th bit: %d\n", n, result);
    return 0;
}
