#include <stdio.h>
int main()
 {
    int num, pos;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position (0-31): ");
    scanf("%d", &pos);
    if (num & (1 << pos))
        printf("Bit %d is SET (1)\n", pos);
    else
        printf("Bit %d is NOT SET (0)\n", pos);

}
