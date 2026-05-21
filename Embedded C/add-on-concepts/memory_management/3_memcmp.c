#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[]="kesava";
    char ptr[]="kesava";
    char*a=str,*b=ptr;
    int result=memcmp(b,a,strlen(a));
    if(result == 0 )
    {
        printf("both strings are same");
    }
    else 
    printf(" not same ");
    
}