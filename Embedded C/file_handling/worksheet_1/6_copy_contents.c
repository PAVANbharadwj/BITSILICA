#include <stdio.h>
#include <stdlib.h>
int main() 
{
    FILE *src, *dest;
    char sourceFile[100], destFile[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%s", destFile);

    src = fopen(sourceFile, "r");
    if (src == NULL) {
        printf("Error: Cannot open source file!\n");
        return 1;
    }

        dest = fopen(destFile, "w");
    if (dest == NULL)
    {
        printf("Error: Cannot create destination file!\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dest);
    }
    printf("\nFile copied successfully.\n");
    fclose(src);
    fclose(dest);
    return 0;
}
