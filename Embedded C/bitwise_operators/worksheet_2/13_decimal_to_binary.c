#include<stdio.h>
int main()
{
    int num;
    printf("enter the number ");
    scanf("%d",&num);
    printf("binary of num is  ");
    for(int i=31;i>=0;i--)
    {
        printf("%d",num>>i&1);
    }


}