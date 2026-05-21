#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[]="kesava";
    char*a=str;
    memmove(a+1,a+2,strlen(a+2)+1);
    puts(str);
}