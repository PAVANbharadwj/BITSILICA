#include<stdio.h>
int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    int swap_bit=(((n)&0xaaaaaaaa>>1)|(((n)&0x55555555<<1)));
    printf("%d",swap_bit);
}