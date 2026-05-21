#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[]="ram";
    char str1[]=" bitsilica";
    int size=sizeof(str)+sizeof(str1);
    char*ptr=(char*)malloc(1*size);
    strcpy(ptr,str);
    strcat(ptr,str1);
    puts(ptr);
}