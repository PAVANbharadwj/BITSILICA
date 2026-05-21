#include<stdio.h>
int main()
{
    int arr[5]={4,7,9,10,22};
    int size,evencount=0,oddcount=0; 
    size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        {
           evencount++;
        }
        else 
        {
        oddcount++;
        }
    }
    printf("evencount:%d\noddcount:%d",evencount,oddcount);
}