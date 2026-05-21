#include<stdio.h>
void convertcase(char ch)
{
    if(ch>=65 && ch<=90)
    {
        printf("lowercase: %c",ch+32);
    }
    else if(ch>=97 && ch<=122)
    {
        printf("uppercase: %c",ch-32);
    }
}
int main()
{
    char ch;
    printf("enter the character: ");
    scanf("%c",&ch);
    void (*convert)(char);
    convert=convertcase;
    convert(ch);
}