#include<stdio.h>
void add(int a,int b);
void sub(int a,int b);
void multi(int a,int b);
void divide(int a,int b);
int main()
{
    int a,b;
    printf("enter values of aand b");
    scanf("%d %d",&a,&b);
    void (*sum)(int,int);
    sum=add;
    sum(a,b);
    void (*p1)(int,int);
    p1=sub;
    p1(a,b);
    void (*p2)(int,int);
    p2=multi;
    p2(a,b);
    void (*p3)(int,int);
    p3=divide;
    p3(a,b);    
}
void add(int a,int b)
{
    printf("sum : %d",a+b);
}
void sub(int a,int b)
{
    printf("\nsub : %d",a-b);
}
void multi(int a,int b)
{
    printf("\nmultiplication : %d",a*b);
}
void divide(int a,int b)
{
    printf("\ndivision : %d",a/b);
}