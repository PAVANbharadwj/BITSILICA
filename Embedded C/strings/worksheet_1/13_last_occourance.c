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
    printf("enter the character you want to remove\n");
    scanf("%c",&ch);
    for(int i=n;i>=0;i--)
    {
        if(ch==str[i])
        {
            for(int j=i;str[j]!='\0';j++)
            {
                str[j]=str[j+1];
                i--;
            }
        }
    }
    puts(str);
}
