#include<stdio.h>
int main()
{
    int a=0,b=1,c;
    int n,count=2,sum=1;
    printf("enter the value of n");
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        count++;
        if(count%2==0)
        {
            sum=sum+b;
        }
        c=a+b;
        a=b;
        b=c;
    }
printf("The sum of even occourance digit is %d",sum);
}