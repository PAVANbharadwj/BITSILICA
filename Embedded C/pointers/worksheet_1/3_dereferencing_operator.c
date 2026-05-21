#include<stdio.h>
int main()
{
    int a=5;
    int*ptr=&a;
    *ptr=20;
    printf("value of ptr=%d\nvalue of a=%d",*ptr,a);
}