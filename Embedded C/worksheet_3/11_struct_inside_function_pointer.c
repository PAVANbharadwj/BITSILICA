#include<stdio.h>

int add (int a,int b);
int sub(int a,int b);
int multply(int a,int b);

struct node
{
    int (*add)(int,int);
    int (*sub)(int,int);
    int (*multply)(int,int);
};

int add (int a,int b)
{
return a+b;
}
int sub (int a,int b)
{
return a-b;
}

int multply (int a,int b)
{
   return a*b;
}
int main()
{
    int a=10,b=20;
    struct node v;
    
    v.add=add;
    v.sub=sub;
    v.multply=multply;

    printf("add: %d\n",v.add(a,b));
    printf("sub: %d\n",v.sub(a,b));
    printf("multply: %d\n",v.multply(a,b));


}