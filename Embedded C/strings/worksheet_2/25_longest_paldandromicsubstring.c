#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],temp[5];
    int n,i,count=0;
    printf("enter string ");
    fgets(str,6,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    n=strlen(str)/2;
    for(i=0;i<n;i++)
    {
        temp[i]=str[i];
    }
    temp[i]='\0';
    int a=0,b=strlen(temp),r=b%2;
    for(int j=0;j<=r;j++)
    {
        if(temp[a]==temp[b])
        {
            a++;
            b--;
        }
        else
        printf("not a palindrome");
    }
    if(a==r)
    {
        puts(temp);
    }

}