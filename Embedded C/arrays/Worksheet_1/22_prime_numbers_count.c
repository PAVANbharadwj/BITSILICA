#include<stdio.h>
int countprime(int num,int n)
{
    int count=0;
        for(int j=2;j<num;j++)
        {
            if(num%j == 0)
            return 0;
        }
return 1;
}
int main()
{
    int arr[5],count=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        if(countprime(arr[i],size))
        {
    printf("%d ",arr[i]);
        count++;
    
        }
    }
printf("\nprime numbers count is%d",count);

}