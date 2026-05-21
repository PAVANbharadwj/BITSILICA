#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void duplicate(char*str)
{
    char*ptr=NULL;
    int n=strlen(str);
    ptr=(char*)malloc(n*sizeof(char));
    int j=0;
    for(int i=0;i<n;i++)
    {
        ptr[j++]=str[i];
    }
    ptr[j]='\0';
    puts(ptr);
}
int main()
{
    char str[]="bitsilica";
    duplicate(str);
}