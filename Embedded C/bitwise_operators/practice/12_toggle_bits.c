#include <stdio.h>
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
    }
}

int main()
{
    int num, n, p;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter number bits");
    scanf("%d", &n);
    printf("Enter starting bit position ");
    scanf("%d", &p);
    printbinary(num);
    num = num | (((1 << n) - 1) << p);
    printf("\n");
    printbinary(num);
}
