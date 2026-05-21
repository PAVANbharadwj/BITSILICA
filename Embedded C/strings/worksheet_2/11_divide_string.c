#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int num,n;
    printf("enter the string ");
    fgets(str,30,stdin);
    if(str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
    printf("enter parts");
    scanf("%d",&num);
    int parts=n/2;
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i;j<=parts;j++)
        {
            printf("%c",str[j]);
        }
    }
}