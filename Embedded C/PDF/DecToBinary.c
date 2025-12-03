#include<stdio.h>
int main(){
    int n,binary[32],i=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n == 0) {
        printf("Binary representation is: 0\n");
        return 0;
    }
    while(n>0){
        binary[i]=n%2;
        n=n/2;
        i++;
    }
    printf("Binary representation is: ");
    for(int j=i-1; j>=0; j--){
        printf("%d", binary[j]);
    }
    return 0;
}