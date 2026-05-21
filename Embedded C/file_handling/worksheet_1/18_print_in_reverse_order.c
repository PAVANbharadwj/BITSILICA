#include <stdio.h>
#include <string.h>

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
     char lines[100][200];
    int count = 0;
    while(fgets(lines[count], sizeof(lines[count]), fp))
    {
        count++;
    }

    fclose(fp);

    printf("\nFile in Reverse Order\n");
    for(int i = count-1; i >= 0; i--)
    {
        printf("%s", lines[i]);
    }

    return 0;
}
