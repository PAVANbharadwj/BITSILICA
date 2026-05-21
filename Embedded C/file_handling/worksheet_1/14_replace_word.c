#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
    char filename[30], temp[] = "temp.txt";
    FILE *fp, *ft;
    char word[50], replace[50], buffer[1000];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter word to replace: ");
    scanf("%s", word);

    printf("Enter new word: ");
    scanf("%s", replace);

    ft = fopen(temp, "w");

    while(fscanf(fp, "%s", buffer) != EOF) 
    {
        if(strcmp(buffer, word) == 0)
            fprintf(ft, "%s ", replace);
        else
            fprintf(ft, "%s ", buffer);
    }

    fclose(fp);
    fclose(ft);

    remove(filename);
    rename(temp, filename);

    printf("Word replaced successfully!\n");

}
