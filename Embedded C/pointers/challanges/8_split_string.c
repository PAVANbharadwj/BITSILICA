#include<stdio.h>
#include<string.h>
void splitstrings(char*ptr,char**first,char**mid)
{
    *first=ptr;
    int len=strlen(ptr);
    int half=len/2;
    ptr[half]='\0';
    *mid=ptr+half+1;
}
int main()
{
    char str[100];
    char*first,*mid;
    printf("enter string");
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    splitstrings(str,&first,&mid);
    printf("%s\n%s",first,mid);
}