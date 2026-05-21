#include<stdio.h>
void isprime(int num);
int main()
{
int num;
printf("enter the number");
scanf("%d",&num);
void (*p)(int);
p=&isprime;
p(num);
}
void isprime(int num)
{
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            printf("not prime");
            return;
        }
    }
    printf("number is prime");

}