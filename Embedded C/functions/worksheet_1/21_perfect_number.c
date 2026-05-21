#include <stdio.h>
int isPerfect(int n) {
int sum = 0;
for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }

    return (sum == n);
}
void printPerfectInRange(int start, int end) 
{
    for (int i = start; i <= end; i++)
    {
        if (isPerfect(i))
            printf("%d ", i);
    }

    printf("\n");
}
int main() {
    int start = 1, end = 100;
    printPerfectInRange(start, end);
}
