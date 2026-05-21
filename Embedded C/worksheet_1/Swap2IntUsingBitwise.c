#include<stdio.h>
int main(){
    int a,b;
    printf("Enter a and b values: ");
    scanf("%d%d",&a,&b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("Swapped a and b: %d %d",a,b);
}