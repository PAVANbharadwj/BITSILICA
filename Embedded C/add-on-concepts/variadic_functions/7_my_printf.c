#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'd')  
        {
            int x = va_arg(args, int);
            printf("%d", x);
            format += 2;
            continue;
        }
        putchar(*format);
        format++;
    }

    va_end(args);
}

int main()
{
    my_printf("The values are: %d %d %d\n", 10, 20, 30);
}
