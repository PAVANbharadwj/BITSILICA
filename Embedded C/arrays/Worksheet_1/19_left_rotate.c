#include<stdio.h>
int main()
{
    int arr[5],n,temp;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter how many times to rotate n");
    scanf("%d",&n);
    n=n%size;
for(int i=0;i<n;i++)
{
    temp=arr[0];
 for(int j=0;j<size;j++)
{
    arr[j]=arr[j+1];
}
arr[size-1]=temp;
}
 for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    

}