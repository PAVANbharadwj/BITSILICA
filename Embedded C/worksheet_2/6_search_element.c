#include<stdio.h>
void searchelement(int*arr,int n,int a);
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]),a;
    printf("enter element to found: ");
    scanf("%d",&a);
    searchelement(arr,n,a);
}
void searchelement(int *arr,int n,int a)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == a)
        {
            printf("element found at index %d",i);
            break;
        }
    }
}