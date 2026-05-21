#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],ch,r='o';
    printf("enter the string");
    fgets(str,10,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    printf("enter the character you want to replace");
    scanf("%c",&ch);
for(int i=0;str[i]!='\0';i++)
{
    if(str[i]==ch)
    {
        str[i]=r;
    }
}
puts(str);
}