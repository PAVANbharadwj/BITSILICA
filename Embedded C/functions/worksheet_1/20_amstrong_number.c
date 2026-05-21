#include <stdio.h>
void isamstrong(int num);
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    isamstrong(num);
}
void isamstrong(int num)
{
    int temp,sum,rem;
    temp=num;
    while(temp)
    {
        rem=temp%10;
        sum=sum+(rem*rem*rem);
        temp=temp/10;

    }
    if(num==sum)
    {
        printf("it is amstrong number");
    }
    else
    printf("not an amstrong number");
}