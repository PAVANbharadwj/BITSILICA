#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int max = 0;  

    for(int i = 0; str[i] != '\0'; i++)
    {
        int count[256] = {0};
        int length = 0;

        for(int j = i; str[j] != '\0'; j++)
        {
            if(count[str[j]] == 1)   
                break;

            count[str[j]] = 1;      
            length++;                
        }

        if(length > max)
            max = length;
    }

    printf("Longest substring length without repeat = %d\n", max);
}
