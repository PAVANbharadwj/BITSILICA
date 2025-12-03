#include <stdio.h>

void printBitsInRange(char ch, int p1, int p2) {
    if (p1 < 0 || p1 > 7 || p2 < 0 || p2 > 7) {
        printf("Positions must be between 0 and 7.\n");
        return;
    }
    if (p1 < p2) {
        int temp = p1;
        p1 = p2;
        p2 = temp;
    }

    printf("Bits from position %d to %d: ", p1, p2);
    for (int i = p1; i >= p2; i--) {
        printf("%d", (ch >> i) & 1);
    }
    printf("\n");
}

int main() {
    char c;
    int pos1, pos2;

    printf("Enter a character: ");
    scanf(" %c", &c);

    printf("Enter two bit positions (0 to 7): ");
    scanf("%d %d", &pos1, &pos2);

    printBitsInRange(c, pos1, pos2);

    return 0;
}
