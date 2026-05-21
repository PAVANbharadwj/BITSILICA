#include<stdio.h>
void swapping (int*a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("\nafter swapping a=%d b=%d",*a,*b);
}
int main()
{
    int a=20,b=30;
    printf("before swapping a=%d b=%d",a,b);
    void (*ptr)(int *,int*);
    ptr=swapping;
    ptr(&a,&b);
}