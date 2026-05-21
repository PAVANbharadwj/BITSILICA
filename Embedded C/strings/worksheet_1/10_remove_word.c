#include <stdio.h>
#include <string.h>
int main()
{
    char str[200], str1[50];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    printf("Enter the word to remove: ");
    fgets(str1, sizeof(str1), stdin);
    if (str1[strlen(str1) - 1] == '\n')
        str1[strlen(str1) - 1] = '\0';
    char result[200]="";
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        if (strcmp(token, str1) != 0)
        {
            strcat(result, token);
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }
    int len = strlen(result);
    if (len > 0 && result[len - 1] == ' ')
        result[len - 1] = '\0';

    puts(result);
}
