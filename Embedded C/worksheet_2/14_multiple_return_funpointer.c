#include<stdio.h>
void compute(int a,int b,int*sum,int*pro)
{
    *sum=a+b;
    *pro=a*b;
}

int main()
{
    int a=10,b=20;
    int sum=0,pro=0;
    void (*ptr)(int,int,int*,int*);
    
    ptr=compute;
    ptr(a,b,&sum,&pro);

    printf("sum=%d\n",sum);
    printf("product=%d",pro);
}