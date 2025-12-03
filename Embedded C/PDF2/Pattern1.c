#include <stdio.h>

int main() {
    int n = 9; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 0) ||
                (i == 1 && j == 1) ||
                (i == 2 && (j == 0 || j == 2)) ||
                (i == 3 && (j == 1 || j == 3)) ||
                (i == 4 && (j == 0 || j == 2 || j == 4)) ||
                (i == 5 && (j == 1 || j == 3)) ||
                (i == 6 && (j == 0 || j == 2)) ||
                (i == 7 && j == 1) ||
                (i == 8 && j == 0)) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}