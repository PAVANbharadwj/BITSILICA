#include<stdio.h>
int main()
{
 int arr[5],num;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter th number");
    scanf("%d",&num);
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(num==arr[i])
        {
            count++;
        }
    }
    printf("%d",count);
}