#include<stdio.h>
int square(int n) {
    return n * n;
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res=square(n);
    printf("Square of %d is: %d\n", n, res);
    return 0;
}