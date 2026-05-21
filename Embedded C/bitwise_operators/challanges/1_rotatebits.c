#include<stdio.h>
void printbinary(int num);
#define rotate_bits(num,p) (num<<p)|(num>>(num-p))
int main()
{
    int num;
    int pos;
    printf("enter the number and position ");
    scanf("%d %d" ,&num,&pos);
    printbinary(rotate_bits(num,pos));
}
void printbinary(int num)
{

for(int i=32;i>=0;i--)
{
    printf("%d",num>>i&1);
}
}
