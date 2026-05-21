#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],temp[25];
    int n;
    printf("enter string1 ");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    n=strlen(str);
    int j=0;
    for(int i=0;str[i]!='\0';i++)
     {
        if(str[i]==' ')
        {
         for(int r=i;str[r]!='\0';r++)
        {
            temp[j]=str[r+1];
            j++;
        }
        }
    }
    temp[j]=' ';
    j++;
    for(int i=0;str[i]!=' ';i++)
    {
        temp[j]=str[i];
    }
    puts(temp);
}