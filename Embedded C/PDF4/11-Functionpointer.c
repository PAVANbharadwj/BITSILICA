#include<stdio.h>
void add(int a,int b){
    printf("%d",a+b);
}
void subtract(int a,int b){
    printf("%d",a-b);
}
void multiply(int a,int b){
    printf("%d",a*b);
}
void divide(int a,int b){
    printf("%d",a/b);
}

int main(){
    int a,b;
    printf("Enter a and b values: ");
    scanf("%d%d",&a,&b);
    void (*fptr[])(int, int) = {add, subtract, multiply, divide};
    int ch;
    printf("Enter choise {0:add 1:subtract 2:multiply 3:Divide}: ");
    scanf("%d",&ch);
    fptr[ch](a,b);
    return 0;
}