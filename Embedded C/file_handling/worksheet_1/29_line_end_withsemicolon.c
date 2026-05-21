#include <stdio.h>
#include <string.h>

int main() 
{
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    char line[200];
    int semicolonCount = 0;
    int blankCount = 0;

    while (fgets(line, sizeof(line), fp)) 
    {
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
        {
            line[len - 1] = '\0';
            len--;
        }

        if (len == 0)
         {
            blankCount++;
            continue;
        }

        if (line[len - 1] == ';')
        {
            semicolonCount++;
        }
    }

    fclose(fp);

    printf("Lines ending with semicolon: %d\n", semicolonCount);
    printf("Blank lines: %d\n", blankCount);
}
