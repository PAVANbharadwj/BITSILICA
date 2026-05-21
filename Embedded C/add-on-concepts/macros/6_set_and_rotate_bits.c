#include<stdio.h>

#define setnbits(data,n,p) data|(((1<<n)-1)<<p)
#define rotateleft(data,x) (x<<data)|(x>>(32-data))
#define rotateright(data,x) (x>>data)|(x<<(32-data))

int main()
{
    int data;
    printf("enter data");
    scanf("%d",&data);
    int n=3,p=0;
    int x=3;
    printf("%d\n",setnbits(data,n,p));
    printf("%d\n",rotateright(data,x));
    printf("%d\n",rotateleft(data,x));

}