#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str1[100];
    printf("enter the string");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    fgets(str1,3,stdin);
    if(str1[strlen(str1)-1]=='\n')
    str1[strlen(str1)-1]='\0';
    char a=str1[0],b=str1[1],c=str1[2];
    for(int i=0;str[i]!='\0';i++)
    {
     if(str[i]==a||b||c)
     {
        str[i]=str[i+1];
     }
    }
    puts(str);
}