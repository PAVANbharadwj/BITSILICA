#include<stdio.h>
#include<string.h>
void countvowels(char*ptr);
int main()
{
    char str[100];
    printf("enter the string: ");
    fgets(str,20,stdin);
    if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';
    void(*p)(char*);
    p=countvowels;
    p(str);
}
void countvowels(char *ptr)
{
    int count;
    for(int i=0;ptr[i]!='\0';i++)
    {
     if(ptr[i] == 'a' ||ptr[i]=='e'|| ptr[i]=='i'|| ptr[i]=='o' || ptr[i] == 'u')
     {
        count++;
     }
    }
    printf("no of vowels in the string is: %d",count);
}