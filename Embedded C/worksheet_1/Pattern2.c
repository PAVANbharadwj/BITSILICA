#include <stdio.h>

int main() {
    int rows = 4;
    int a = 0, b = 1, c=1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", c);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    return 0;
}
