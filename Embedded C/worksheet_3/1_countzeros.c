#include<stdio.h>
void countzeros(int num)
{
    int count=0;
    int temp=num;

    while(temp)
    {
        int digit=temp%10;
        if(digit == 0)
        {
            count++;
        }
        temp /=10;
    }

    printf("no of zeros in binary is %d",count);
}


int main()
{
    int num;
    printf("enter binary number ");
    scanf("%d",&num);
    countzeros(num);
}