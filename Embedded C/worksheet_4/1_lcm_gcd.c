#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the value of a and b");
    scanf("%d%d",&a,&b);
    int gcd,lcm;
    int num1=a,num2=b;
     while(a!=b)
     {
        if(a>b)
            a=a-b;
            else
            b=b-a;
    }
    gcd=a;
    lcm=(num1*num2)/gcd;

    printf("lcm = %d\ngcd=%d",lcm,gcd);


}