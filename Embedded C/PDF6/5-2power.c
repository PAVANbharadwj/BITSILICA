#include <stdio.h>

int main() {
    int num, nextPower = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 1) {
        printf("Next power of 2 is 1\n");
        return 0;
    }
    while (nextPower < num)
        nextPower *= 2;
    printf("%d is %d\n", num, nextPower);
    return 0;
}
