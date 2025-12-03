#include <stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  
        n >>= 1;
    }
    return count;
}
int main() {
    int n1, n2;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    int xorResult = n1 ^ n2;
    int bitFlips = countSetBits(xorResult);
    printf("Number of bits to convert %d to %d is %d\n", n1, n2, bitFlips);
    return 0;
}