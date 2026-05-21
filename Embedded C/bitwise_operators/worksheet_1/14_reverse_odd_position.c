#include <stdio.h>
int reverseOddBits(int n) 
{
    int oddBits=0,rev=0;
    int i, j = 0;
    for (i=1; i < 32; i += 2) {
        if (n & (1 << i))
            oddBits |= (1 << j);
        j++;
    }
    while (oddBits) {
        rev <<= 1;
        rev |= (oddBits & 1);
        oddBits >>= 1;
    }
    int result = n;
    j = 0;
    for (i = 1; i < 32; i += 2) 
    {
        result &= ~(1 << i);        
        if (rev & (1 << j))
            result |= (1 << i);
        j++;
    }

    return result;
}
int main() 
{
    int n;
    printf("Enter a number");
    scanf("%d", &n);
    printf("After reversing odd bits: %d\n", reverseOddBits(n));
    return 0;
}
