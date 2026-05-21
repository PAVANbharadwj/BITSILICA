#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str1[100],temp[10];
    int count=0;
    printf("enter string1 ");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    printf("enter string2 ");
    fgets(str1,10,stdin);
    if(str1[strlen(str1)-1]=='\n')
    str1[strlen(str1)-1]='\0';
    printf("enter string: ");
    fgets(temp,10,stdin);
    if(temp[strlen(temp)-1]=='\n')
    temp[strlen(temp)-1]='\0';
    int n=strlen(temp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(str[i]==temp[j])
            count++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(str1[i]==temp[j])
            count++;
        }
    }
if(count>=n)
{
    printf("true");
}
else 
printf("false");
}