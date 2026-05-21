#include<stdio.h>
#include<string.h>
void changecase(char*str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i]=str[i]+32;
        }
        else if(str[i]>=90 && str[i]<=122)
        {
            str[i]=str[i]-32;
        }
    }
}

int main()
{
    char str[50];
    printf("enter the string: ");
    
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';

    changecase(str);
    printf("after changing case: ");
    puts(str);
}