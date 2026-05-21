#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[]="kesava";
    char*a=str;
    char*ptr=memchr(a,'v',strlen(str));
    printf("%c",*ptr);
}