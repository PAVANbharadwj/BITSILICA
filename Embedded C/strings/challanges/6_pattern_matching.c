#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str1[100];
    char*ptr=NULL;
    printf("enter the string\n");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    printf("enter string2 ");
    fgets(str1,10,stdin);
    if(str1[strlen(str1)-1]=='\n')
    str1[strlen(str1)-1]='\0';
    ptr=str;
    while((ptr=strstr(ptr,str1))!=NULL)
    {
        printf("%d",ptr-str);

    }

}