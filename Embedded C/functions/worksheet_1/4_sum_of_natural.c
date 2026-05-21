#include <stdio.h>
int sum(int n) 
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}
int main()
{
    int sum1,n;
    printf("Enter a number: ");
    scanf("%d", &n);
    sum1=sum(n);
    printf("Sum of natural numbers up to %d is %d\n", n, sum1);
}
