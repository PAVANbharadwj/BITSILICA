#include<stdio.h>
#include<stdarg.h>
void minmax(int count,...)
{
    int min,max;
    va_list arg;
    va_start(arg,count);
    min=va_arg(arg,int);
    max=min;
    for(int i=1;i<count;i++)
    {
        int x=va_arg(arg,int);
        if(x>max)
        {
            max=x;
        }
        else if(x<min)
        {
            min=x;
        }
        
    }
    printf("min: %d max: %d ",min,max);
    va_end(arg);
}
int main()
{
    minmax(5,1,2,3,4,5);
}