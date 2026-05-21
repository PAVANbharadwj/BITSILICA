#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[5];
    int*ptr=arr;
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int num;
    printf("enter the location of element you want to print");
    scanf("%d",&num);
    if(num>=n)
    {
        printf("undefinde behaviour memory accessing outside the array is leads to undefined results\nplease select locationbetween 0 t0 4");
        exit(0);
    }
    else
    {
        printf("%d",*ptr+num);
    }
}