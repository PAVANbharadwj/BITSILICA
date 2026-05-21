#include<stdio.h>
#include<stdlib.h>
void calculate_average(int*arr[],int n);
int main()
{
    int*arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(1*sizeof(int));
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
    calculate_average(arr,n);
    for(int i=0;i<n;i++)
    {
        free(arr[i]);
    }

}
    
void calculate_average(int*arr[],int n)
{
    int sum=0;
    
    for(int i=0;i<n;i++)
     {
        sum+=*arr[i];
     }

     int average=sum/n;

     printf("The average of elements is: %d",average);
}