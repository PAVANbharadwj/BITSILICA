#include <stdio.h>
int findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int largest = findLargest(arr, size);
    printf("The largest element in the array is : %d\n", largest);
}
