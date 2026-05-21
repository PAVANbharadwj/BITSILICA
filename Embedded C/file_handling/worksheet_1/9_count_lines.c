#include <stdio.h>
int main() 
{
    FILE *fp;
    char filename[100];
    char ch;
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n') 
        {
            count++;
        }
    }

    fclose(fp);
    if (count > 0 || ch != EOF)
    {
        count++;
    }
    printf("Total number of lines: %d\n", count);
    return 0;
}
