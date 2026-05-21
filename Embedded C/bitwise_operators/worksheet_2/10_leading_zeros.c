#include <stdio.h>
int main()
{
    unsigned int num;
    int count = 0;
    printf("Enter a number ");
    scanf("%u", &num);
    if (num == 0) {
        printf("All bits are zero\n");
        return 0;
    }
    for (int i=31;i>=0;i--)
     {  
        if (num & (1 << i))
        break;       
        count++;
    }
    printf("Number of leading zeros: %d\n", count);
    return 0;
}
