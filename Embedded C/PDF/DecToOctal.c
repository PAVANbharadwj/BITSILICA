#include<stdio.h>
int main(){
    int n,i=0,octal[32];
    printf("Enter a decimal number: ");   
    scanf("%d", &n);
    if(n == 0) {
        printf("Octal representation is: 0\n");
        return 0;
    }
    while(n > 0){
        octal[i] = n % 8;
        n = n / 8;
        i++;
    }
    printf("Octal representation is: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", octal[j]);
    }
    return 0;
}