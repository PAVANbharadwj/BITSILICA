#include <stdio.h>

int main() {
    int n = 5;  
    int num = 1;
    for (int i = 1; i <= n; i++) {
        int row[i];
        for (int j = 0; j < i; j++) {
            row[j] = num++;
        }
        if (i % 2 == 0) {
            for (int j = i - 1; j >= 0; j--) {
                printf("%d ", row[j]);
            }
        } else {
            for (int j = 0; j < i; j++) {
                printf("%d ", row[j]);
            }
        }
        printf("\n");
    }
    return 0;
}