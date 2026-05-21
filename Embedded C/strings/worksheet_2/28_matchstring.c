#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],ptr[100];
    int count=0;
    printf("enter the string");
    fgets(str,30,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    printf("enter second string");
    fgets(ptr,30,stdin);
    if (ptr[strlen(ptr) - 1] == '\n')
    ptr[strlen(ptr) - 1] = '\0';
    int n,r=strlen(ptr);
    n=r/2;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==ptr[i])
        count++;
    }
    if(count>=n)
printf("true");
}