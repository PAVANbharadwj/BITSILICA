#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    int n=strlen(str);
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[i]==str[j])
            {
            memmove(str+j,str+j+1,strlen(str+j)+1);
            j--;
            }
        }
    }
    puts(str);
}