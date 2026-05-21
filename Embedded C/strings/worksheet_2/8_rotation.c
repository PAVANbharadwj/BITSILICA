#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str1[100];
    int i,count=0;
    printf("enter string1 ");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    printf("enter string2 ");
    fgets(str1,10,stdin);
    if(str1[strlen(str1-1)]=='\n')
    str1[strlen(str1-1)]='\0';
    int n=strlen(str);
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(str[i]==str1[j])
            count++;
        }
    }
if(count==n)
{
    printf("true");
}
else 
printf("false");
}