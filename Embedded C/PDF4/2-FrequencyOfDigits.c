#include <stdio.h>

int main() {
    int num, digit;
    int freq[10] = {0}; 
    printf("Enter an integer: ");
    scanf("%d", &num); 
    if (num < 0)
        num = -num;
    while (num > 0) {
        digit = num % 10;
        freq[digit]++;
        num /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("Digit %d: %d times\n", i, freq[i]);
        }
    }

    return 0;
}
