#include<stdio.h>
void sorting(int*ptr,int n);
int main()
{
 int arr[6];
 printf("enter the elements");
 for(int i=0;i<6;i++)
 {
    scanf("%d",&arr[i]);
 }
 int n=6;
void (*p)(int*,int);
p=sorting;
p(arr,n);
}
void sorting(int*ptr,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(ptr[j]>ptr[j+1])
            {
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
}

