#include <stdio.h>
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    int (*p)(int);
    p=fibonacci;
    for(int i=0;i<n;i++)
    {
        printf("%d\t",p(i));
    }
}
