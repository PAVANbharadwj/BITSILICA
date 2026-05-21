#include <stdio.h>

int main()
{
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);   
    fclose(fp);

    printf("Size of file '%s': %ld bytes\n", filename, size);

    return 0;
}
