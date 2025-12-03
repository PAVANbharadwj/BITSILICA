#include<stdio.h>

#define SWAP(n1,n2) { int temp = n1; n1 = n2; n2 = temp; }

int main(){
    int n1,n2;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&n1,&n2);
    SWAP(n1, n2);
    printf("After swap: %d %d\n", n1, n2);
}