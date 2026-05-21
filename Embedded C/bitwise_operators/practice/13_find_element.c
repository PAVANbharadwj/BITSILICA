#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,2,1};
    int res=0,i;
    for(i=0;i<5;i++)
    {
        res=res^arr[i];
    }
    printf("%d",res);
}