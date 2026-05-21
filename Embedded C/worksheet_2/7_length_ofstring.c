#include<stdio.h>
void findlength(char*str)
{
    int count=0;
    for(int i=0;str[i]!='\0';i++)
    {
        count++;
    }
    printf("length of string is %d",count);
}


int main()
{
    char str[]="abcdef";
    findlength(str);
}