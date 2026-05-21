#include<stdio.h>
int main()
{
    int num=10;
    int*ptr=&num;
    int**pptr=&ptr;
    printf("num=%d\n",num);
    printf("ptr=%d\n",ptr);
    printf("pptr=%d",pptr);
    printf("dereference ptr=%d\n",*ptr);
    printf("dereference pptr=%d",**pptr);

}