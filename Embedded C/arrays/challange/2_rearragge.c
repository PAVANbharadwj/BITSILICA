#include <stdio.h>
int main()
{
    int arr[5],temp[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
for(int i=0;i<n;i++)
{
    if(i/2==0 && arr[i]>0 )
    {
        temp[i]=arr[i];
    }
    else
    {
        temp[i]=arr[i];
    }
}
for(int i=0;i<n;i++)
{
printf("%d ",temp[i]);
}
}