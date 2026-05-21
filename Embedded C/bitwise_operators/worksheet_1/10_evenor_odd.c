#include<stdio.h>
void check_powerof_2(int num);
int main()
{
    int num;
    printf("enter the number ");
    scanf("%d",&num);
    check_powerof_2(num);
}
void check_powerof_2(int num)
{
    if(num&1)
    {
        printf("even number");
    }
    else
    printf("odd number");
}