#include<stdio.h>
int main(){
    int p,t,r;
    printf("Enter principal amount, time in years and rate of interest: ");
    scanf("%d %d %d", &p, &t, &r);
    float si = (p * t * r) / 100.0;
    printf("Simple Interest is: %.2f\n", si);
    return 0;
}