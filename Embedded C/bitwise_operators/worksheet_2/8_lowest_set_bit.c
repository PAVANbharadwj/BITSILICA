#include <stdio.h>
int main()
{
    int num, pos=-1;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("No bits are set.\n");
        return 0;
    }
    for (int i=0;i<32;i++)  
    {   
        if (num&(1<<i)) {
            pos = i;
            break;
        }
    }

    printf("Lowest set bit position: %d\n", pos);
}
