#include<stdio.h>
void buttonstatus(int data);
int main()
{
    int data;
    printf("enter the status of button");
    scanf("%d",&data);
    void(*p)(int);
    p= buttonstatus;
    p(data);
}
void buttonstatus(int data)
{
    if(data==1)
    {
        printf("switch pressed\nOn mode");
    }
    else if(data==0)
    {
        printf("switch not pressed\nOff mode");
    }
    else
    printf("enter valid data to button 0 or 1");
}