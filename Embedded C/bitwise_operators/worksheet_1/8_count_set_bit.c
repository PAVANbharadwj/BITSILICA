#include<stdio.h>
void setbit(int num,int bit);
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",num>>i&1);
    }
}
int main()
{
    int num,bit;
    printf("enter the number");
    scanf("%d",&num);
    printf("enter the bit you need to set");
    scanf("%d",&bit);
    printf("before setting\n");
    printbinary(num);
    setbit(num,bit);
}
void setbit(int num,int bit)
{
    num=num|(1<<bit);
    printf("\nafter setting\n");
    printbinary(num);
}

