#include <stdio.h>
int octalToDecimal(int octal) {
    int decimal = 0, base = 1, rem;
    while (octal != 0) {
        rem = octal % 10;
        decimal += rem * base;
        base *= 8;
        octal /= 10;
    }
    return decimal;
}
int decimalToOctal(int decimal) {
    int octal = 0, place = 1;
    while (decimal != 0) {
        octal += (decimal % 8) * place;
        decimal /= 8;
        place *= 10;
    }
    return octal;
}

int main()
 {
    int octalInput = 17;
    int decimalInput = 15;
    int dec = octalToDecimal(octalInput);
    int oct = decimalToOctal(decimalInput);
    printf("Decimal %d\n", dec);
    printf("Octal %d\n",oct);
}