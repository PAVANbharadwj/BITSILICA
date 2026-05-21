#include <stdio.h>

int main() 
{
    int num, digit;
    int freq[10] = {0}; 

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0) 
    {
        digit = num % 10;   
        freq[digit]++;    
        num = num / 10;    
    }

    printf("\nDigit Frequency:\n");
    for (int i = 0; i < 10; i++) 
    {
        if (freq[i] > 0)
            printf("Digit %d occurs %d times\n", i, freq[i]);
    }
}
