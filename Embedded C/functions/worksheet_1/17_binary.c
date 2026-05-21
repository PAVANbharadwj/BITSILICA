#include <stdio.h>
int main()
{
    int num, binary = 0, base = 1, rem;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    int n = num;
    while (n > 0) 
    {
        rem = n % 2;
        binary = binary + rem * base;
        n = n / 2;
        base = base * 10;
    }
    printf("Binary number: %d\n", binary);
}
