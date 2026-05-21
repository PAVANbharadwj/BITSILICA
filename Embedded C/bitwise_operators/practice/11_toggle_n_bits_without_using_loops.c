#include <stdio.h>
int main() 
{
    int num, n;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter number of bits to toggle");
    scanf("%d", &n);
    int mask = (1 << n) - 1;
    int result = num ^ mask;  
    printf("Result after toggling %d bits: %d\n", n, result);
}
