#include <stdio.h>
int reverse(int n, int rev) {
    if (n == 0) return rev;
    else return reverse(n / 10, rev * 10 + n % 10);
}
int palindrome(int n) {
    return n == reverse(n, 0);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (palindrome(n)) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
    return 0;
}