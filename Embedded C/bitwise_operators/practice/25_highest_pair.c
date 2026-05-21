#include<stdio.h>
int main()
{
    int data,bit,count=0,max=0,position;
    printf("enterdata\n");
    scanf("%d",&data);
    for(bit=31;bit>=0;bit--)
    {
      printf("%d",((data>>bit)&1));
    }
     for(bit=31;bit>=0;bit--)
     {
      if(((data>>bit)&1)==0)
     count=0;
       else if(((data>>bit)&1)==1)
     count++;
    if(count>max)
   {
     max=count;
     position=((bit+max)-1);
    }
    }
 
  printf("\nhighest bit start at %d and count is%d",position,max);
 }