#include <stdio.h>

int main() {
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            count++;
        } else {
            if (count > max)
                max = count;
            count = 1;
        }
    }

    if (count > max)
        max = count;

    printf("\nTotal longest consecutive length: %d\n", max);

    return 0;
}
