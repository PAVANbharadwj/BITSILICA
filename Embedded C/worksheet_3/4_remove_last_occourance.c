#include <stdio.h>
#include <string.h>

int main() 
{
    char str[200] = "Hello world, welcome to the world";
    char word[] = "world";

    char *last = NULL;
    char *temp = str;

    while ((temp = strstr(temp, word)) != NULL) 
    {
        last = temp;  
        temp++;        
    }

    if (last) 
    {
        memmove(last, last + strlen(word), strlen(last + strlen(word)) + 1);
        printf("After removal: %s\n", str);
    } 
    else
    {
        printf("Word not found.\n");
    }
}
