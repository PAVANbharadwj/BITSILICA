#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int count=0;
    printf("enter the string\n");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    int temp=str[0];
    for(int i=1;str[i]!='\0';i++)
    {
        if(temp==str[i])
        {
            break;
        }
        else
        count++;
    }
    for(int i=0;i<=count;i++)
    {
        printf("%c",str[i]);
    }
}