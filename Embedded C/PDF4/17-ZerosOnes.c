#include <stdio.h>

#define COUNT_ONES(num) countOnes(num)
#define COUNT_ZEROS(num) (sizeof(num) * 8 - countOnes(num))

int countOnes(unsigned int num) {
    int count = 0;
    while (num) {
        count += (num & 1);  
        num >>= 1;           
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter n value: ");
    scanf("%d",&num);
    printf("Total 1s: %d\n", COUNT_ONES(num));
    printf("Total 0s: %d\n", COUNT_ZEROS(num));

    return 0;
}
