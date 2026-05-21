#include<stdio.h>
int main()
{
int arr[5],size;
size=5;
printf("enter the elements into array\n");
for(int i=0;i<size;i++)
{
    scanf("%d",&arr[i]);
}
printf("The elements in the array are ");
for(int i=0;i<size;i++)
{
    printf("%d ",arr[i]);
}
}