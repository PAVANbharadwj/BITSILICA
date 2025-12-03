#include<stdio.h>
int main(){
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 1.8) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    return 0;
}