#include<stdio.h>
int main()
{
    int num=10;
    int*ptr;
    printf("before %d\n",*ptr);
    ptr=&num;
    printf("after %d",*ptr);

}