#include <stdio.h>
void checkEvenOdd(int n) {
    if (n % 2 == 0)
        printf("The entered number is even.\n");
    else
        printf("The entered number is odd.\n");
}
int main()
{
    int num;
    printf("Input: ");
    scanf("%d", &num);
    checkEvenOdd(num);
}
