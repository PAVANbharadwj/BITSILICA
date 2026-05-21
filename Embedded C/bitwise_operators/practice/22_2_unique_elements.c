#include<stdio.h>
int main()
{
int arr[6]={1,2,3,1,9,9};
int n=sizeof(arr)/sizeof(arr[0]);
int xor;
for(int i=0;i<n;i++)
{
    xor^=arr[i];
}
int setbit=xor & -xor;
int x,y;
for(int i=0;i<n;i++)
{
    if(arr[i] & setbit)
    x^=arr[i];
    else
    y^=arr[i];

}
printf("two unique values are %d %d",x,y);
}