#include <stdio.h>

#define FLIP_BITS(x) (~(x))

int main() {
    unsigned int num = 5;

    printf("Original: %u\n", num);
    printf("Flipped : %u\n", FLIP_BITS(num));

    return 0;
}
