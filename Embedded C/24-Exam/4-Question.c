#include <stdio.h>

void sortDescending(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k: ");
    scanf("%d", &k);

    if(k <= 0 || k > n) {
        printf("Invalid value of k.\n");
        return 1;
    }
    sortDescending(arr, n);
    printf("The %dth largest element is: %d\n", k, arr[k - 1]);
    return 0;
}
