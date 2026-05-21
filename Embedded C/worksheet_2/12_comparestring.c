#include<stdio.h>
#include<string.h>
int mystrcmp(char*str,char*arr)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>arr[i])
        {
            return 1;
        }
        else if(str[i]<arr[i])
        {
            return-1;
        }

    }
    return 0;
}

int main()
{
    char str[10],arr[10];
    printf("enter the string1: ");
    fgets(str,10,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    
    printf("enter the string2: ");
    fgets(arr,10,stdin);
    if(arr[strlen(arr)-1]=='\n')
    arr[strlen(arr)-1]='\0';

    int n= mystrcmp(str,arr);
    if(n==0)
    {
        printf("both strings are same");
    }
    else if(n>0)
    {
        printf("string1 is greater than string2");
    }
    else if(n<0)
    {
        printf("string 2 is greater than string 1");
    }


}