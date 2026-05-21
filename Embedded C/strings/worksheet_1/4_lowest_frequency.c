#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter the string");
    fgets(str,10,stdin);
    printf("\nOccurrences of all elements:\n");
    for (int i = 0;str[i]!='\0'; i++)
    {
        int count = 1;
        if (str[i] == -1) 
            continue;
        for (int j = i + 1;str[j]!='\0'; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = -1; 
            }
        }

        printf("%c occurs %d times\n", str[i], count);
    }
}