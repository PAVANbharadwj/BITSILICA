#include <stdio.h>
#include <string.h>

int main() 
{
    char str[50], longest[20], temp[20];
    printf("Enter the string: ");
    fgets(str, 50, stdin);

    int j = 0, maxlen = 0;
    for(int i = 0; ; i++)
     {
        if(str[i] != ' ' && str[i] != '\0') 
        {
            temp[j++] = str[i]; 
        } 
        else
        {

            if(strlen(temp) > maxlen)
             { 
                maxlen = strlen(temp);
                strcpy(longest, temp);
            }

            j = 0;            
        }

        if(str[i] == '\0')   
            break;
    }

    printf("The longest word is '%s' and its length is %d\n", longest, maxlen);
}
