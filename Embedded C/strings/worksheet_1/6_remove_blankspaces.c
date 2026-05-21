#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string");
    fgets(str,10,stdin);
    if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    for(int j=0;str[j]!='\0';j++)
    {
       if(str[j]==' ')
            {
            memmove(str+j,str+j+1,strlen(str+j)+1);
            j--;
            }
    }
    puts(str);
}