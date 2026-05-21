#include <stdio.h>
#include <string.h>
int main()
{
    char word[100], list[10][100];
    int n;
     printf("Enter the word: ");
    scanf("%s", word);
    printf("Enter number of strings: ");
    scanf("%d", &n);
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++)
    scanf("%s", list[i]);
    printf("Strings containing all characters of '%s':\n", word);
    for (int i = 0; i < n; i++)
    {
        int match = 1;
        for (int j = 0; j < strlen(word); j++)
        {
            if (strchr(list[i], word[j]) == NULL)
            {
                match = 0;
                break;
            }
        }
        if (match)
            printf("%s ", list[i]);
    }
}
