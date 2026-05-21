#include <stdio.h>
int main() 
{
    unsigned int x = ~0;
    int count = 0;
    while (x != 0) 
    {
        x = x >> 1;  
        count++;     
    }
    printf("Size of integer: %d bits\n", count);
    return 0;
}
