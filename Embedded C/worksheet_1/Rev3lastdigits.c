#include<stdio.h>
int main() {
    int n;
    printf("Enter number of 6 digits: ");
    scanf("%d", &n);

    int count = 0;
    int temp = n;

    // Count digits
    while(temp != 0) {
        count++;
        temp /= 10;
    }

    if(count != 6) {
        printf("Invalid Number\n");
        return 1;
    }

    int first3 = n / 1000;   
    int last3 = n % 1000;    
    int rev = 0;
    for(int i = 0; i < 3; i++) {
        rev = rev * 10 + last3 % 10;
        last3 /= 10;
    }

    int result = first3 * 1000 + rev;
    printf("Number after reversing last 3 digits: %d\n", result);

    return 0;
}
