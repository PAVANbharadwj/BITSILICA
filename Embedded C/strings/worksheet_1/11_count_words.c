#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int count=0;
    printf("enter the string");
    fgets(str,30,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            count++;
        }
    }
printf("no of words are %d",count+1);
}