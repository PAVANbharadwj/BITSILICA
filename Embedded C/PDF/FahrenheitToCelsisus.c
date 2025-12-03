#include<stdio.h>
int main(){
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");    
    scanf("%f", &fahrenheit);
    float celsius = (fahrenheit - 32) / 1.8;
    printf("Temperature in Celsius: %.2f\n", celsius);
    return 0;
}