#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';

    char *words[20];
    int wordCount = 0;

    char *token = strtok(str, " ");
    while(token != NULL) 
    {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    int maxLen = 0;
    for(int i = 0; i < wordCount; i++)
    {
        int len = strlen(words[i]);
        if(len > maxLen) maxLen = len;
    }


    for(int i = 0; i < maxLen; i++)
     {
        for(int j = 0; j < wordCount; j++) 
        {
            if(i < strlen(words[j]))
                printf("%c ", words[j][i]);
            else
                printf("  ");  
        }
        printf("\n");
    }
}
