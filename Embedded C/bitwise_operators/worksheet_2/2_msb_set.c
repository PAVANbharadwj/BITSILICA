#include<stdio.h>
void statuslsb(int num);
void statusmsb(int num);
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
    }
}
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    printbinary(num);
    statuslsb(num);
    statusmsb(num);
}
void statuslsb(int num)
{
    if(num&1)
    {
        printf("\nstatus is set");
    }
    else
    printf("\nstatus is clear");

}
void statusmsb(int num)
{
    if(num&(1<<31))
    {
        printf("\nstatus is set");
    }
    else
    {
        printf("\nstatus is clear");
    }
}