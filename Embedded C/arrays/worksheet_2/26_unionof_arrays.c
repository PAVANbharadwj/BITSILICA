#include<stdio.h>
int main()
{
    int arr[3],str[3];
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array1\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter elements to array2\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&str[i]);
    }
    int flag;
    for(int i=0;i<size;i++)
    {
    printf("%d ",arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        flag=0;
        for(int j=0;j<size;j++)
        {
        if(str[i]==arr[j])
        {
            flag=1;
            continue;
        }
        }
        if(!flag)
        {
            printf("%d",str[i]);
        }
    }
}


