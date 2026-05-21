#include<stdio.h>
void printelement(int *ptr);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printelement(arr);
}
void printelement(int *ptr)
{
    int num;
    printf("enter the location of element you want to print");
    scanf("%d",&num);
    printf("the element is %d",*(ptr+num));
}