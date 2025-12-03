#include<stdio.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    int num=(n<<3)+(n<<1);
    printf("%d multiplied by 10 is: %d",n,num);
    return 0;
}