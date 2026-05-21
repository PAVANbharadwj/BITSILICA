#include<stdio.h>
int add(int x,int y);
int sub(int x,int y);
struct op
{
    int (*add)(int,int);
    int (*sub)(int,int);
};
int main()
{
    struct op v;
    int x=10,y=20;
    v.add=add;
    v.sub=sub;
    printf("add: %d\n",v.add(x,y));
    printf("sub: %d",v.sub(x,y));
}
int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
