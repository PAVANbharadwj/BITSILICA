#include<stdio.h>
#include<string.h>
void removespaces(char*ptr)
{
int i,j=0;
char str[100];
for(i=0;ptr[i]!='\0';i++)
{
    if(ptr[i] != ' ')
    {
    str[j]=ptr[i];
    j++;
    }
}
str[j]='\0';
puts(str);
}
int main()
{
    char str[100];
    printf("enter string");
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    removespaces(str);
}