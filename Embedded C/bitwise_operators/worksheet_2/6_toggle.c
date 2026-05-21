#include <stdio.h>
int main()
{
    int num, pos;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to toggle (0-31): ");
    scanf("%d", &pos);
    num = num ^ (1 << pos);
    printf("result %d\n", num);
}
