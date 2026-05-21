#include<stdio.h>
int main()
{
 int arr[5],small,secondsmall;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    if(arr[0]<arr[1])
    {
        small=arr[0];
        secondsmall=arr[1];
    }
    else
    {
        small=arr[1];
        secondsmall=arr[0];
        
    }
     for(int i=2;i<size;i++)
    {
        if(arr[i]<small)
        {
            secondsmall=small;
            small=arr[i];
        }
    else if(arr[i]<secondsmall && arr[i]!=small)
    {
        secondsmall=arr[i];
    }
}

printf("small:%d\nsecondsmall:%d\n",small,secondsmall);
}