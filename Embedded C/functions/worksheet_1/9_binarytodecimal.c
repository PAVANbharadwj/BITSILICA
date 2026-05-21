#include <stdio.h>
int binaryToDecimal(int bin) 
{
int dec = 0, base = 1, rem;
    while (bin > 0)
    {
        rem = bin % 10;
        dec = dec + rem * base;
        bin = bin / 10;
        base = base * 2;
    }
    return dec;
}
int decimalToBinary(int dec) {
    int bin = 0, base = 1, rem;
    while (dec > 0) {
        rem = dec % 2;
        bin = bin + rem * base;
        dec = dec / 2;
        base = base * 10;
    }
    return bin;
}
int main()
{
    int bin, dec;
    printf("Enter a binary number: ");
    scanf("%d", &bin);
    printf("Decimal %d\n",binaryToDecimal(bin));
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    printf("Binary %d\n",decimalToBinary(dec));
}
