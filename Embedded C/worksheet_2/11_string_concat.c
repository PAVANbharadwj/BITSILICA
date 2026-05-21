#include<stdio.h>
#include<string.h>
void mystrcat(char*str,char*arr)
{
    char ptr[40];
    int j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        ptr[j++]=str[i];
    }
    for(int i=0;arr[i]!='\0';i++)
    {
        ptr[j++]=arr[i];
    }
    ptr[j]='\0';

    puts(ptr);
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

    mystrcat(str,arr);

}