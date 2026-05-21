#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[50];
    char ch;
    int lines = 0, words = 0;
    int inWord = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("File cannot be opened.\n");
        return 1;
    }
    
    while ((ch = fgetc(fp)) != EOF)
    {

        if (ch == '\n')
            lines++;

        if (ch != ' ' && ch != '\n' && ch != '\t')
         {
            if (inWord == 0)
            {
                words++;
                inWord = 1;
            }
        } 
        else
        {
            inWord = 0;
        }
    }

    fclose(fp);
    if (words > 0 && ch != '\n')
        lines++;

    printf("\nTotal Lines: %d\n", lines);
    printf("Total Words: %d\n", words);
}
