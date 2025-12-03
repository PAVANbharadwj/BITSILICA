#include <stdio.h>

int square(int x) {
    return x * x;
}

int cube(int x) {
    return x * x * x;
}

void applyOperation(int arr[], int size, int (*operation)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = operation(arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    applyOperation(arr, size, square);
    printf("After squaring: ");
    printArray(arr, size);

    applyOperation(arr, size, cube);
    printf("After cubing: ");
    printArray(arr, size);

    return 0;
}
