#include<stdio.h>

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int org=n;
    int rem=0,rev=0;
    while(n!=0){
        rem=n%10;
        rev+=rem*rem*rem;
        n=n/10;
    }
    if(rev==org){
        printf("Perfect");
    }
    else{
        printf("Not Perfect");
    }
    return 0;
}