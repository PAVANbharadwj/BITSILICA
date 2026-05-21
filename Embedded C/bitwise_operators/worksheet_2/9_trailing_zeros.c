#include <stdio.h>
int main()
{
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("All bits are zero.\n");
        return 0;
    }
    while ((num&1) == 0)
    {  
        count++;
        num >>= 1;      
    }
    printf("Number of trailing zeros: %d\n", count);
}
