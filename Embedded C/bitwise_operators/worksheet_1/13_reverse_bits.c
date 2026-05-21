#include <stdio.h>
void printbinary(int num);
unsigned int reverseBits(unsigned int num)
{
    unsigned int rev = 0;
    int i;
    for (i = 0; i < 32; i++) 
    {  
        rev <<= 1;              
        if (num & 1)           
            rev |= 1;          
        num >>= 1;              
    }
    return rev;
}
int main() {
    unsigned int n;
    printf("Enter an integer: ");
    scanf("%u", &n);
    unsigned int reversed = reverseBits(n);
    printbinary(reversed);

    return 0;
}
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
    }
}