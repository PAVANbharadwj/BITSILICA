#include <stdio.h>
int countbits(int a, int b)
{
    int xor = a ^ b;  
    int count = 0;
    while (xor != 0)
    {
        if (xor & 1) 
            count++;
        xor = xor >> 1; 
    }
    return count;
}
int main()
{
    int A, B;
    printf("Enter two integers A and B: ");
    scanf("%d %d", &A, &B);
    printf("Number of bits to flip: %d\n", countbits(A, B));
}