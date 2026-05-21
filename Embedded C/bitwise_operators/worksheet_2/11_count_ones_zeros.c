#include <stdio.h>
int main() 
{
    unsigned int num;
    int ones = 0, zeros = 0;
    printf("Enter a number: ");
    scanf("%u", &num);
    for (int i = 0; i < 32; i++) 
    {
        if (num & (1 << i))
            ones++;      
        else
            zeros++;  
    }
    printf("Number of 1s %d\n", ones);
    printf("Number of 0s %d\n", zeros);
}
