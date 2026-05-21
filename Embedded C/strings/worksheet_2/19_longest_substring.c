#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    int max = 0;        
    int count = 0;        
    char sub[100];       
    char longest[100];    

    for (int i = 0; i < n; i++)
    {
        count = 1;
        sub[0] = str[i];
        for (int j = i + 1; j < n; j++)
        {
            int repeat = 0;
            for (int k = 0; k < count; k++)
            {
                if (sub[k] == str[j]) 
                {
                    repeat = 1;
                    break;
                }
            }
            if (repeat)
                break;
            sub[count++] = str[j];
        }
        sub[count] = '\0';
        if (count > max) 
        {
            max = count;
            strcpy(longest, sub);
        }
    }

    printf("Longest substring : %s\n", longest);
    printf("Length = %d\n", max);
}