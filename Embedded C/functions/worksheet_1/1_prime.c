#include<stdio.h>
int isprime(int i);
int main()
{
    int min,max,i;
    printf("enter min number");
    scanf("%d",&min);
    printf("enter max number");
    scanf("%d",&max);
    for(i=min;i<max;i++)
    if(isprime(i))
    {
        printf("%d ",i);
    }
}
int isprime(int i)
{
int j;
for(j=2;j<i;j++)
{
    if(i%j==0)
    return 0;
}
return 1;
}