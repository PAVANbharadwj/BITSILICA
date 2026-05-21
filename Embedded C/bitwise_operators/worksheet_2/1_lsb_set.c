#include<stdio.h>
void setlsb(int num);
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    setlsb(num);
}
void setlsb(int num)
{   
    printf("before setting lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num>>0|1;
    printf("\nater setting lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}