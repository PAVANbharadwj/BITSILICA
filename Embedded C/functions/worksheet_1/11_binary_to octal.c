#include <stdio.h>
int binaryToDecimal(long binary)
{
    int decimal = 0, base = 1, rem;
    while (binary > 0) {
        rem = binary % 10;
        decimal = decimal + rem * base;
        base = base * 2;
        binary = binary / 10;
    }
    return decimal;
}
int decimalToOctal(int decimal) {
    int octal = 0, base = 1, rem;
    while (decimal > 0) {
        rem = decimal % 8;
        octal = octal + rem * base;
        base = base * 10;
        decimal = decimal / 8;
    }
    return octal;
}
int main() {
    long binary = 110011;
    int decimal, octal;

    decimal = binaryToDecimal(binary);
    octal = decimalToOctal(decimal);

    printf("Binary %ld = Octal %d\n", binary, octal);

    return 0;
}
