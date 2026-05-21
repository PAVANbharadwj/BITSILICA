#include<stdio.h>
void printarray(int arr[],int n);

void sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

}

void merge (int a[],int n,int b[],int m)
{
    int i=0,j=0,k=0;
    int r[12];
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            r[k]=a[i];
            i++;
            k++;
        }
        else
        {
            r[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        r[k]=a[i];
        k++;
        i++;
    }
    while(j<m)
    {
        r[k]=b[j];
        k++;
        j++;
    }
    printf("the smallest element is %d",r[0]);
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[]={1,5,3,6,9,2};
    int b[]={1,3,9,5,7,6};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    sort(a,n);
    sort(b,m);
    printarray(a,n);
    printarray(b,m);
    merge(a,n,b,m);
}
