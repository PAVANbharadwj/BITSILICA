#include <stdio.h>
int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], copiedarr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *parr = arr;
    int *pcopiedarr = copiedarr;

    for (int i = 0; i < n; i++) {
        *(pcopiedarr + i) = *(parr + i);
    }
    printf("Copied array elements: ");
    for(i = 0; i < n; i++) {
        printf("%d ", copiedarr[i]);
    }
    return 0;
}