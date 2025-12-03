#include<stdio.h>
int prime(int n){
    if(n<=1)return 0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("First %d prime numbers are: ", n);
    int count = 0, num = 2;
    while(count < n) {
        if(prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    return 0;
}