#include<stdio.h>
void set_lsb_nibble(int num);
void set_msb_nibble(int num);
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    set_lsb_nibble(num);
    set_msb_nibble(num);

}
void set_lsb_nibble(int num)
{   
    printf("before setting lsb nibble\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num|0x000f;
    printf("\nater setting lsb nibble\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}
void set_msb_nibble(int num)
{   
    printf("\nbefore setting msb nibble\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
    num=num|0xf0000000;
    printf("\nafter setting msb nibble\n");
    for(int i=31;i>=0;i--)
    {
    printf("%d",num>>i&1);
    }
}
