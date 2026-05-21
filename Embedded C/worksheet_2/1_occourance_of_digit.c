#include<stdio.h>
int main()
{
    int num,a,temp,count=0;
    printf("enter the number: ");
    scanf("%d",&num);
    printf("\nenter number you need to find: ");
    scanf("%d",&a);
    temp=num;
    while(temp!=0)
    {
        num=temp%10;
        if(num==a)
        count++;
        temp=temp/10;
    }
    printf("occurance of digit %d in number %d is %d",a,num,count);
}