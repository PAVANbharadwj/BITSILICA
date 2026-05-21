#include<stdio.h>
int main()
{
    int num,count=0;
    printf("enter the number");
    scanf("%d",&num);
    for(int i=31;i>=0;i--)
    {
    if(num>>i&1)
    count++;
    }
    printf("setbit count is%d",count);
}