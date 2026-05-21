#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[]="kesava";
    char*a=str;
    memset(a+3,'*',1);
    puts(str);
    
}