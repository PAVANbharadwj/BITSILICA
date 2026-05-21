#include <stdio.h>
#include <stdarg.h>

double average(int count, ...)
{
    va_list args;
    va_start(args, count);
    double sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        double value = va_arg(args, double);
        sum += value;
    }
    va_end(args);
    return sum / count;
}

int main()
{
    double result = average(4, 10.5, 30.2, 40.1, 20.6);
    printf("The average is: %lf\n", result);
}