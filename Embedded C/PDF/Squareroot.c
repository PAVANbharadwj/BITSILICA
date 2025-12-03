#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res=sqrt(n);
    printf("Square root of %d is: %d\n", n, res);
    return 0;
}