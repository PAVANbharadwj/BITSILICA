#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    char ch[100];
    int count=0;
    printf("enter the string ");
    fgets(str,30,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    printf("enter the string ");
    fgets(ch,30,stdin);
    if (ch[strlen(ch) - 1] == '\n')
    ch[strlen(ch) - 1] = '\0';
    int n=strlen(ch);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==ch[0])
        {
            count++;
        }
           
    }
    printf("%d",count);
}
