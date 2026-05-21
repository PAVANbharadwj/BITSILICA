#include<stdio.h>
void setlsb(int num);
void clearlsb(int num);
void togglelsb(int num);
void setmsb(int num);
void clearmsb(int num);
void togglemsb(int num);
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    setlsb(num);
    clearlsb(num);
    togglelsb(num);
    setmsb(num);
    clearmsb(num);
    togglemsb(num);

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

void clearlsb(int num)
{   
    printf("\nbefore clearing lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num>>0&(~1);
    printf("\nafter clearing lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}

void togglelsb(int num)
{   
    printf("\nbefore toggle lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num>>0^1;
    printf("\nater toggle lsb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}

void setmsb(int num)
{   
    printf("\nbefore setting msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num|(1<<31);
    printf("\nater setting msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}
void clearmsb(int num)
{   
    printf("\nbefore clearing msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num & ~(1<<31);
    printf("\nafter clearing msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}

void togglemsb(int num)
{   
    printf("\nbefore toggle msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num^(1<<31);
    printf("\nater toggle msb\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}