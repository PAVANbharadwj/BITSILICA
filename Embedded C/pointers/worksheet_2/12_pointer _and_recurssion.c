#include <stdio.h>
#include <string.h>
void reverseString(char *start, char *end)
{
    if (start >= end)  
        return;
    char temp = *start;
    *start = *end;
    *end = temp;

    reverseString(start + 1, end - 1);
}

int main()
{
    char str[] = "Hello World!";
    printf("Original string: %s\n", str);
    
    reverseString(str, str + strlen(str) - 1);
    
    printf("Reversed string: %s\n", str);
}
