#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
void order(char *str, int start, int end)
{
    if (start == end)
        printf("%s\n", str);
    else 
    {
        for (int i = start; i <= end; i++)
        {
            swap(&str[start], &str[i]);
            order(str, start + 1, end);
            swap(&str[start], &str[i]);
        }
    }
}
int main()
{
    char str[] = "ABCD";
    order(str, 0, strlen(str) - 1);
    return 0;
}