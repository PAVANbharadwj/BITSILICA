#include<stdio.h>
#include<string.h>
void sort (char*str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[i]>str[j])
            {
                char temp = str[j];
                str[j] = str[i];
                str[i]=temp;
            }
        }
    }
    puts(str);
}





int main()
{
    char str[50];
    printf("enter the string: ");
    
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';

    sort(str);
}