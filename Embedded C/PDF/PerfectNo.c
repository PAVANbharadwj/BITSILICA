#include<stdio.h>
int main(){
    int n,sum=0;
    printf("Enter a number: "); 
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        if(n%i==0){
            sum += i;
        }
    }
    if(sum==n){
        printf("The number is a Perfect number.\n");
    } else {
        printf("The number is not a Perfect number.\n");
    }
    return 0;
}