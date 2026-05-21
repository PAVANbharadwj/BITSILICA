#include <stdio.h>

int sumOfSquares(int n)
{
    int sum = 0;
    while(n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int isHappy(int n)
{
    int slow = n, fast = n;
    do
    {
        slow = sumOfSquares(slow);              
        fast = sumOfSquares(sumOfSquares(fast));  

        if(fast == 1)
            return 1;

    } while(slow != fast);

    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    if(isHappy(num))
        printf("%d is a Happy Number\n", num);
    else
        printf("%d is NOT a Happy Number\n", num);
}