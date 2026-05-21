#include<stdio.h>
#include<stdarg.h>
int sum(int count,...)
{
    va_list args;
    va_start(args,count);
    int sum=0;
    for(int i=0;i<count;i++)
    {
        int x=va_arg(args,int);
        sum=sum+x;
    }
    va_end(args);
    return sum;
}

int main()
{
printf("sum of digits is %d\n",sum(5,1,2,3,4,5));   
}
