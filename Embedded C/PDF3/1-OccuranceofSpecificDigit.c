#include<stdio.h>
int main(){
    int n;
    printf("Enetr n value: ");
    scanf("%d",&n);
    int ele;
    printf("enter number to find: ");
    scanf("%d",&ele);
    int rem=0,count=0;
    while(n!=0){
        rem=n%10;
        if(rem==ele){
            count++;
        }
        n=n/10;
    }
    printf("%d occurs %d times:",ele,count);
    return 0;
}