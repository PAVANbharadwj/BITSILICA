#include<stdio.h>
int main()
{
    int arr[5];
    int prodect=1,size;
    size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements into array");
    for(int i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
    for(int i=0;i<size;i++)
    {
        prodect=prodect*arr[i];
    }
printf("The sum of elements in the array are:%d",prodect);
}