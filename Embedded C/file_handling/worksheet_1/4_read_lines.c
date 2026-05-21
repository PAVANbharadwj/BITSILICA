#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

int main() 
{
    FILE *fp;
    char filename[50];
    char lines[MAX_LINES][MAX_LENGTH]; 
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) 
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(lines[count], MAX_LENGTH, fp) != NULL && count < MAX_LINES) 
    {
        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    fclose(fp);
    printf("\nStored lines as array elements:\n");

    for (int i = 0; i < count; i++) 
    {
        printf("%d: %s\n", i, lines[i]);
    }
}