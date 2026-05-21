#include <stdio.h>
#include <stdlib.h>

char* readLine() 
{
    char *line = NULL;
    int size = 0;
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        char *temp = realloc(line, size + 1);
        if (temp == NULL) 
        {
            free(line);
            return NULL;
        }
        line = temp;
        line[i++] = ch;
        size++;
    }
    char *temp = realloc(line, size + 1);
    if (temp == NULL)
    {
        free(line);
        return NULL;
    }
    line = temp;
    line[i] = '\0';

    return line;
}

int main()
{
    printf("Enter a line: ");
    char *str = readLine();
    if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("You entered: %s\n", str);
    free(str);
    return 0;
}