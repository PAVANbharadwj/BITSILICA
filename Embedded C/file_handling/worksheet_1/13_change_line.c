#include<stdio.h>
int main()
{
    char filename[20], temp[] = "text.txt";
    printf("enter filename: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("error while opening file");
        return 1;
    }
    
    int line, cline = 1;
    printf("enter the line you need to modify: ");
    scanf("%d", &line);

    getchar();
    
    char newtext[100];
    printf("enter text to modify: ");
    fgets(newtext, sizeof(newtext), stdin);

    FILE *ft = fopen(temp, "w");
    if(ft == NULL)
    {
        printf("error while creating file");
        return 1;
    }
    
    char ch;
    while((ch = getc(fp)) != EOF)
    {
        if(line == cline)
        {
            fprintf(ft, "%s", newtext);
            while(ch != '\n' && ch != EOF)
                ch = getc(fp);
        }
        else
        {
            putc(ch, ft);
        }

        if(ch == '\n')
            cline++;
    }

    fclose(ft);
    fclose(fp);

    remove(filename);
    rename(temp, filename);

    printf("Line modified successfully.\n");
}
