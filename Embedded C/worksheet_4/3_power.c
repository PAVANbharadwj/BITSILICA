#include<stdio.h>
int power(int x,int n)
{
    if(n==0)
        return 1;
    return x*power(x,n-1);
}

int main()
{
    int x,n;
    printf("enter the value of x and y: ");
    scanf("%d %d",&x,&n);
   printf("%d", power(x,n));
}