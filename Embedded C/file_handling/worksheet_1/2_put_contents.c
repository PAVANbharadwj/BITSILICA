#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char filename[100], ch;
    printf("Enter file name to open: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) 
    {
        printf("Error: File does not exist or cannot be opened.\n");
        return 1;  
    }
    printf("\n--- File Contents ---\n\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}
