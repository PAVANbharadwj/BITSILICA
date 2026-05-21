#include <stdio.h>
int factorial(int n)
 {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
     return fact;
}
int seriesSum() {
    int sum = 0;
    for (int i = 1; i <= 5; i++)
        sum += factorial(i) / i;
    return sum;
}
int main() {
    int result;
    result = seriesSum();
    printf("The sum of the series is : %d\n", result);
}
