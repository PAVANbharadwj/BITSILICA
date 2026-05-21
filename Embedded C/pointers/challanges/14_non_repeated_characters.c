#include<stdio.h>
#include<string.h>
void print_non_repeated_elements(char*ptr)
{
    int count;
    for(int i=0;ptr[i]!='\0';i++)
    {
        count=0;
        for(int j=0;ptr[j]!='\0';j++)
        {
            if(ptr[i]==ptr[j])
            {
                count++; 
            }
        }
        if(count==1)
        printf("%c ",ptr[i]);
    }
}
int main()
{
    char str[100];
    printf("enter the string: ");
    fgets(str,15,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    print_non_repeated_elements(str);
}
