#include<stdio.h>
void reversearray(int *ptr,int n);
void pointerindexing(int *ptr,int n);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    pointerindexing(arr,n);
    reversearray(arr,n);
}
void pointerindexing(int *ptr,int n)
{
    printf("the elements in the array are: ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",*(ptr+i));
    }
}
void reversearray(int *ptr,int n)
{
    int temp;
    int*start=ptr;
    int *end=ptr+n-1;
    while(start<end)
    {
        temp=*end;
        *end=*start;
        *start=temp;
        start++;
        end--;
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
    printf("%d ",*(ptr+i));
    }
}
