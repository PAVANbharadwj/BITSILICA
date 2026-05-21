#include <stdio.h>
int binary_togray(int num)
{
return num^(num>>1);
}
int main()
{
    int num;
    printf("enter number");    
    scanf("%d",&num);
    num=binary_togray(num);
    printf("binary to gray %d\n",num);
}
