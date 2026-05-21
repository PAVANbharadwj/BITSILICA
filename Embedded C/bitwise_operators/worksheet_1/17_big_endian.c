#include <stdio.h>
void printbinary(int num);
int main() 
{
    unsigned int num, result;
    printf("Enter a number: ");
    scanf("%u", &num);
    result = ((num >> 24) & 0x000000FF) |
             ((num >> 8)  & 0x0000FF00) |
             ((num << 8)  & 0x00FF0000) |
             ((num << 24) & 0xFF000000);
    printbinary(result);

}
void printbinary(int num)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(num>>i)&1);
    }
}