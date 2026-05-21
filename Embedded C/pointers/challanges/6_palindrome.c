#include<stdio.h>
#include<string.h>
void palindromecheck(char*ptr)
{
    char*end,*start;
    start=ptr;
    end=ptr+strlen(ptr)-1;
    while(start<end)
    {
        if(*start != *end)
        {
            printf("not a palindrome");
        }
        start++;
        end--;
    }
    printf("it is an palindrome");
}
int main()
{
    char str[100];
    printf("enter string");
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str-1)]='\0';
    palindromecheck(str);
}