#include<stdio.h>
int cube(int n) {
    return n * n * n;
}   
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res=cube(n);
    printf("Cube of %d is: %d\n", n, res);
    return 0;
}