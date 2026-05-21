#include <stdio.h>

#define SWAP(a,b) a^=b^=a^=b

int main() {
    int x = 10, y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    SWAP(x, y);

    printf("After swap:  x = %d, y = %d\n", x, y);
}
