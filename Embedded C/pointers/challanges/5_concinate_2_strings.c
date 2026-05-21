#include <stdio.h>
int main(void)
{
    char str1[50] = "Hello ";
    char str2[] = "C Programming";
    char *p = str1;
    while (*p != '\0')
    {
        p++;
    }
    char *q = str2;
    while (*q != '\0') {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    printf("Concatenated: %s\n", str1);
}

