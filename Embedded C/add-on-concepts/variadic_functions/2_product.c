#include<stdio.h>
#include<stdarg.h>
int product(int count,...)
{
    int product=1;
    va_list arg;
    va_start(arg,count);
    for(int i=0;i<count;i++)
    {
        int x=va_arg(arg,int);
        product*=x;
    }
    va_end(arg);
    return product;
}

int main()
{
    printf("the product is %d\n",product(5,1,2,3,4,5));
}