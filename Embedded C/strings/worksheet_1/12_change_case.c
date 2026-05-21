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
        if(str[i]>=65 &&str[i]<=90 )
        {
            str[i]=str[i]+32;
        }
        else if(str[i]>=97 &&str[i]<=122 )
        {
            str[i]=str[i]-32;
        }

    }
    puts(str);
}