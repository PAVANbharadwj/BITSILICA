#include <stdio.h>
int main() 
{
    int num, pos, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position to clear (0-31): ");
    scanf("%d", &pos);
    result = num & ~(1 << pos); 
    printf("%d\n",result);
}
