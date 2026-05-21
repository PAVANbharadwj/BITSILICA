#include<stdio.h>
int main()
{
    int a=10;
    int *ptr=NULL;
    if(ptr==NULL)
    {
        ptr=&a;
    }
    printf("%d",*ptr);
}