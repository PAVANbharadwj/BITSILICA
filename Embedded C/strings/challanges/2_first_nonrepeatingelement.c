#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int temp,i;
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    int n=strlen(str);
    temp=str[0];
    for(i=1;str[i]!='\0';i++)
    {
            if(temp!=str[i])
            {
                printf("%c",str[i]);
                break;
            }
            else
            temp=str[0+i];

    }
}