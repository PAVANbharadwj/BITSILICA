#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    printf("enter 4digit numaric value");
    fgets(str,5,stdin);
    int num=0;
    for(int i=0;str[i]!='\0';i++)
    {
        num=num*10+(str[i]-'0');
    }
    printf("%d",num);

}