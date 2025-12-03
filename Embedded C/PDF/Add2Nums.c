#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int main(){
    int a,b;
    printf("Enter A & B values:" );
    scanf("%d%d",&a,&b);
    printf("Addition of 2 numbers: %d",add(a,b));
    return 0;
}