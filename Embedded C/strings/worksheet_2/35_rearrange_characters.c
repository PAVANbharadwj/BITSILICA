#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],temp[100];
    int count=0;
    printf("enter string1 ");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    temp[0]=str[0];
    for(int i=1;str[i]!='\0';i++)
    {
        if(str[i]!=temp[i-1])
        {
            temp[i]==str[i];
        }
    }
puts(temp);
}