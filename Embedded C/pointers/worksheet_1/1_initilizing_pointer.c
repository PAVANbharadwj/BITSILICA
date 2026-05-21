#include<stdio.h>
int main()
{
    int a=5;
    int*ptr=&a;
    printf("value of ptr=%d\nvalue of a=%d",*ptr,a);
}