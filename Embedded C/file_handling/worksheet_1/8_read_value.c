#include <stdio.h>
int main() 
{
    FILE *fp;
    char filename[50];
    int num;
    printf("Enter file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fscanf(fp, "%d", &num);
    fclose(fp);
    printf("Read variable: %d\n", num);

    int newValue = 300;

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error writing to file.\n");
        return 1;
    }

    fprintf(fp, "%d", newValue);
    fclose(fp);
    printf("After writing value %d, file now contains: %d\n", newValue, newValue);
    return 0;
}

