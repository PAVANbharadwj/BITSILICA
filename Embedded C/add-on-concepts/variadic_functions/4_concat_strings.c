#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void concat_strings(int count, ...)
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
    printf("Concatenate strings: %s\n", buffer);
}

int main()
{
    concat_strings(3, "BitLearn", ".", "Bitsilica");
    concat_strings(4, "Hello", " ", "World", "!");
}