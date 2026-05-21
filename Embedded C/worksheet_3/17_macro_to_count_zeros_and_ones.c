#include <stdio.h>

#define COUNT_ONES(num, count)       \
{                                    \
    count = 0;                       \
    unsigned int n = num;            \
    while(n) {                       \
        if(n & 1) count++;           \
        n >>= 1;                     \
    }                                \
}

#define COUNT_ZEROS(num, count)      \
{                                    \
    count = 0;                       \
    unsigned int n = num;            \
    while(n) {                       \
        if((n & 1) == 0) count++;    \
        n >>= 1;                     \
    }                                \
}

int main() {
    unsigned int num = 13;

    int ones, zeros;

    COUNT_ONES(num, ones);
    COUNT_ZEROS(num, zeros);

    printf("Number: %u\n", num);
    printf("Count of 1s: %d\n", ones);
    printf("Count of 0s: %d\n", zeros);

    return 0;
}
