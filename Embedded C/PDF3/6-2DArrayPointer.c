#include <stdio.h>

int main() {
    int rows = 2, cols = 3;
    int arr[2][3] = {{1, 2, 3},{4, 5, 6}};

    printf("Accessing elements using pointer notation:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}
