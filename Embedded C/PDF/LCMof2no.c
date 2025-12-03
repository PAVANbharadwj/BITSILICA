#include<stdio.h>
int main(){
    int a,b,max;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int lcm;
    max=(a>b)?a:b;
    while(1){
        if(max%a==0 && max%b==0){
            lcm=max;
            break;
        }
        max++;
    }
    printf("LCM of %d and %d is: %d\n", a, b, lcm);
    return 0;
}