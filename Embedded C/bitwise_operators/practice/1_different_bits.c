#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int x = a ^ b;
    int count = 0;
    while (x)
    {
        count += x & 1; 
        x >>= 1;  
    }
    printf("Number of differing bits: %d\n", count);
}
