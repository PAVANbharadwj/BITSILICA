#include<stdio.h>
void printelement(int *ptr);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
     scanf("%d",&arr[i]);
   int *p1,*p2;
   p1=&arr[2];
   p2=&arr[5];
   if(p1>p2)
   {
    printf("pl point to the element after p2");
   }
  
  else
    printf("p1 is pointing to element before p2");
}