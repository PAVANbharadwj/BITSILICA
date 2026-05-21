#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reversestring(char*ptr,int n);
int main()
{
    char *str1,*str2;
    char*ptr;
    str1=(char*) malloc(100 * sizeof(char));
    str2=(char*) malloc(100*sizeof(char));
    if(str1==NULL && str2==NULL)
    {
        printf("memory allocation failed");
        exit(0);
    }
    printf("enter the string1\n");
    fgets(str1,10,stdin);
    printf("enter the string2\n");
    fgets(str2,10,stdin);
    strcat(str1,str2);
    int n=sizeof(str1);
    reversestring(str1,n);
    free(str1);
    free(str2);


}
void reversestring(char*ptr,int n)
{
    char *start,*end;
    start=ptr;
    end=ptr+n-1;
    char temp;
    while(start<end)
    {
        temp=*end;
        *end=*start;
        *start=temp;
        start++;
        end--;
    }
    puts(ptr);
}