#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[100];
    int n;
    char line[200];

    printf("Enter file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "a");
    if (fp == NULL) 
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter number of new lines: ");
    scanf("%d", &n);

    getchar();
    printf("Enter lines:\n");
    for (int i = 0; i < n; i++) 
    {
        fgets(line, sizeof(line), stdin);
        fputs(line, fp);
    }
    fclose(fp);
    printf("\nLines appended successfully.\n");
}
