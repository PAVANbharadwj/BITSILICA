#include<stdio.h>
#define togglebit(data,n) data=data^(1<<n)

int main()
{
    int num,n;
    printf("enter number: ");
    scanf("%d",&num);
    printf("enter bit to toggle: ");
    scanf("%d",&n);
    num=togglebit(num,n);
    printf("%d",num);
}