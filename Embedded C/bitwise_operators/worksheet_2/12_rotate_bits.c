#include <stdio.h>
int main() 
{
    unsigned int num, d, result;
    printf("Enter a number: ");
    scanf("%u", &num);
    printf("Enter number of bits to rotate left: ");
    scanf("%u", &d);
    result = (num << d) | (num >> (32 - d));  
    printf("After left rotation: %u\n", result);
}
