#include<stdio.h>
void check_powerof_2(int num);
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    check_powerof_2(num);
}
void check_powerof_2(int num)
{
    if(num>0 && (num & (num-1)))
    {
        printf("not power of 2");
    }
    else
    printf("it is power of 2");
}