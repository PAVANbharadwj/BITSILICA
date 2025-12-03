#include<stdio.h>
#include<string.h>
#include<math.h>
int decimal(char binary[]){
    int decimal=0;
    int length = strlen(binary);
    for(int i=0; i<length; i++){
        if(binary[i]=='1'){
            decimal += pow(2, length-i-1);
        }
    }
    return decimal;
}
int main(){
    char binary[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    int dec = decimal(binary);
    printf("Decimal value of %s is %d\n", binary, dec);
    return 0;
}