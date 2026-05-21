#include<stdio.h>
int main()
{
    int a=5,b=10;
    printf("before swapping a=%d b=%d\n",a,b);
    a^=b^=a^=b;
    printf("after swapping a=%d b=%d",a,b);
}