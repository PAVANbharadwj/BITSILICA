#include <stdio.h>

int main() {
    int arr[100], result[100];
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            result[index++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0)
            result[index++] = arr[i];
    }
    printf("Array after separating even and odd: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}