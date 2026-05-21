#include <stdio.h>
int countZeros(int n) 
{
    if (n==0)
        return 0;
    if (n%10==0)
        return 1 + countZeros(n/10);
    else
        return countZeros(n/10);
}
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("Number of zeros: %d\n",countZeros(num));
}
