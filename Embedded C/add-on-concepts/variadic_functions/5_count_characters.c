#include <stdio.h>
#include <stdarg.h>
#include <string.h>
void count_characters(int count, ...)
{
    char buffer[200] = "";
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char*);
        strcat(buffer, str);
    }

    va_end(args);
    printf("count: %d\n",strlen(buffer)-1);
}

int main()
{
    count_characters(3, "BitLearn", ".", "Bitsilica");
}
