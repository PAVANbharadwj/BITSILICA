#include<stdio.h>
void sort(int*arr)
{
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] < arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void printarray(int*arr)
{
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void merge(int*a,int*b)
{
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(a)/sizeof(b[0]);
    
    int r[n+m];
    int l=0;
    
    int i=0,j=0;

}




int main()
{
    int a[]={1,9,8,4,3},b[]={5,3,6,7,2};
    sort(a);
    sort(b);
}