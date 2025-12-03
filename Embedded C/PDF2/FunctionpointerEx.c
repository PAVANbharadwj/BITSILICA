#include<stdio.h>
void sum(int a,int b){
    printf("Sum is: %d",a+b);
}
void sub(int a,int b){
    printf("Sub is: %d",a-b);
}
void mul(int a,int b){
    printf("Mul is: %d",a*b);
}
void divd(int a,int b){
    printf("Divd is: %d",a/b);
}
void main(){
    int a,b,c;
    void (*fptr[])(int,int)={sum,sub,mul,divd};
    printf("Enter your choice (0:Sum, 1:Sub, 2:Mul, 3:Div): ");
    scanf("%d",&c);
    printf("Enter a and b values: ");
    scanf("%d%d",&a,&b);
    fptr[c](a, b);
}