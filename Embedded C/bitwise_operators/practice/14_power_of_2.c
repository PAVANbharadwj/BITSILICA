#include<stdio.h>
int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    if((n)>0 && (n & (n-1))==0)          //if(num>0 && (num &(num-1)==0)
    {
    printf("power of 2");
    }
    else
    printf("not power of 2");

}
