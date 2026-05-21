#include<stdio.h>

int main()
{
    int a=10,b=20,c=30;

    int*arr[3];

    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;

    for(int i=0;i<3;i++)
    {
        printf("%d ",*arr[i]);
    }

}