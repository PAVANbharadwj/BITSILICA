#include <stdio.h>

int main()
{
    char filename[50], temp[] = "temp.txt";
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    FILE *ft = fopen(temp, "w");
    if(ft == NULL)
    {
        printf("Error creating temp file.\n");
        fclose(fp);
        return 0;
    }

    char ch;

    while((ch = getc(fp)) != EOF)
    {
        ch = ch - 3;  
        putc(ch, ft);
    }

    fclose(fp);
    fclose(ft);

    remove(filename);
    rename(temp, filename);

    printf("File encrypted successfully.\n");

    return 0;
}
