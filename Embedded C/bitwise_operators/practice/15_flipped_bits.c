#include<stdio.h>
int main()
{
    int a,b,count=0,xor;
    printf("enter the data");
    scanf("%d %d",&a,&b);
    xor=a^b;
    while(xor!=0)
    {
    if(xor&1)
    count++;
    xor>>=1;
    }
     printf("%d",count);

}