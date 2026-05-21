#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string: ");
    fgets(str,10,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    int n=strlen(str);
    char*ptr=(char*)malloc(1*n);
    strcpy(ptr,str);
    puts(ptr);
    free(ptr);
    ptr=NULL;
}