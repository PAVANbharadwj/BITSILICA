#include<stdio.h>
int main()
{
    int  arr[5];
    int size,found; 
    size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter the element to be found\n");
    scanf("%d",&found);
    for(int i=0;i<size;i++)
    {
        if(arr[i]==found)
        {
            printf("element found at index:%d\n",i);
                break;
        }
        else
        {
            printf("element not found");
        }
        
    }

}