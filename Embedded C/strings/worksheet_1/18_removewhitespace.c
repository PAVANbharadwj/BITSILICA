#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    char ch=' ';
    printf("enter the string ");
    fgets(str,30,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    int n=strlen(str);
    int i;
    if(ch==str[0])
        { 
        for(i=0;str[i]!='\0';i++)
        {
           str[i]=str[i+1];
        }

        }
        if(str[n]==ch)
        {
        str[n]=ch;
        }
        puts(str); 
}