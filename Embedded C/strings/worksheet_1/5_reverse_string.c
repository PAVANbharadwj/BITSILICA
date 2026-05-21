#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int temp,i;
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    int n=strlen(str);
    printf("%d",n);
    for(i=0;i<n;i++)
    {
        if(str[i]!=str[n-1])
        {
            temp=str[i];
            str[i]=str[n-1];
            str[n-1]=temp;
        }
        n--;
    }
    puts(str);
}