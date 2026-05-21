#include<stdio.h>
void changecase(char ch);
int main()
{
    char ch;
    printf("enter the character: ");
    scanf("%c",&ch);
    void(*fp)(char);
    fp=changecase;
    fp(ch);
}
void changecase(char ch)
{
if(ch>=65 && ch<=90)
{
    printf("%c",ch+32);
}
else if(ch>=90 && ch<=122)
{
    printf("%c",ch-32);
}
}