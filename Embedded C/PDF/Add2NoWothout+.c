#include<stdio.h>
int sum(int a, int b) {
    while(b!=0){
        int n=a&b;
        a=a^b;
        b=n<<1;
    }
    return a;
}
int main(){
    int a, b;
    printf("Enter two numbers: ");  
    scanf("%d %d", &a, &b);
    int result=sum(a,b);
    printf("Sum of %d and %d is: %d\n", a, b, result);
    return 0;
}