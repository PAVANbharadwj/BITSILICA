#include <stdio.h>

int square(int x)
{
    return x * x;
}

int processNumber(int num, int (*callback)(int))
{
    return callback(num);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int result = processNumber(n, square);

    printf("Square of %d = %d\n", n, result);

    return 0;
}
