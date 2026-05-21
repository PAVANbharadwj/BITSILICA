#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int count,a,sum;
    printf("enter the string");
    fgets(str,10,stdin);
    if(str[strlen(str-1)]=='\n')
    str[strlen(str-1)]='\0';
    int n=strlen(str);
    for(int i=0;str[i]!='\0';i++)
    { 
        count=1;
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
            if(count>sum)
            {
                a=i;
              sum=count;  
            }

        }
    }
    printf("character:%c times:%d",str[a],sum);
}
