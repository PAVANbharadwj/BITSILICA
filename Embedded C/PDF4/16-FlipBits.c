#include <stdio.h>

#define FLIP_BITS(num) (~(num))

int main() {
    unsigned int num;
    printf("enter n value: ");
    scanf("%lu",&num);
    unsigned int result = FLIP_BITS(num);
    printf("After flipping bits: %lu\n", result);
    return 0;
}