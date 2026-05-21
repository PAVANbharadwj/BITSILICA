#include<stdio.h>
void printbinary (int num);
union a
{
    float num;
    int roll;
};
int main()
{
    union a v={20.5};
    printbinary(v.roll);
}
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
    }
}