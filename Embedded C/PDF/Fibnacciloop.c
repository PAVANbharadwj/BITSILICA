#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int a=0,b=1,c=1;
    for (int i = 0; i < n; i++) {
    if (i <= 1)
        c = i;
    else {
        c=a+b;
        a = b;
        b = c;
    }
    printf("%d ", c);
}

    printf("\n");
    return 0;
}