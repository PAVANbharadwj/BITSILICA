#include<stdio.h>

int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int resultGCD = gcd(num1, num2);
    int resultLCM = lcm(num1, num2);

    printf("GCD of %d and %d = %d\n", num1, num2, resultGCD);
    printf("LCM of %d and %d = %d\n", num1, num2, resultLCM);

    return 0;
}
