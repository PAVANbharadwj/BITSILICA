#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    char ch;
    printf("enter the string ");
    fgets(str,30,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    int n=strlen(str);
    printf("enter the character you want position\n");
    scanf("%c",&ch);
    for(int i=n;i>=0;i--)
    {
        if(ch==str[i])
        {
           printf("last occourance position is%d",i);
           break;
        }
    }
}