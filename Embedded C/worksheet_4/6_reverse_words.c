#include<stdio.h>
#include<string.h>

void reversegroup(char *str, int k);

int main()
{
    char str[] = "one two three four five six";
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    reversegroup(str, k);
}

void reversegroup(char *str, int k)
{
    char words[50][50];
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) 
    {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i += k) 
    {
        int start = i;
        int end = (i + k - 1 < count) ? (i + k - 1) : (count - 1);

        while (start < end) 
        {
            char temp[50];
            strcpy(temp, words[start]);
            strcpy(words[start], words[end]);
            strcpy(words[end], temp);
            start++;
            end--;
        }
    }

    for (int i = 0; i < count; i++) 
    {
        printf("%s ", words[i]);
    }
}