#include<stdio.h>
#include<stdlib.h>
int main()
{
    int*arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int));
        if(arr[i]==NULL)
        {
            printf("memory allocation failed");
            return 0;
        }
    }
    printf("enter elements to array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr[i]);
    }
    
    int sum=0;
    
    for(int i=0;i<n;i++)
     {
        sum+=*arr[i];
     }

     int average=sum/n;

     printf("The average of elements is: %d",average);
}