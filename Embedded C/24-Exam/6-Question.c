#include <stdio.h>

int main() {
    int n, start, end;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter start index: ");
    scanf("%d", &start);
    printf("Enter end index: ");
    scanf("%d", &end);

    if(start < 0 || end >= n || start > end) {
        printf("Invalid");
        return 1;
    }

    for(int i = start; i < end; i++) {
        for(int j = i + 1; j <= end; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array after sorting subarray [%d to %d]:\n", start, end);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
