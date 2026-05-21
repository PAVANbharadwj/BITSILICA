#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[]="kesava";
    char ptr[10];
    char*a=str,*b=ptr;
    memcpy(b,a,strlen(str)+1);
    puts(ptr);
}