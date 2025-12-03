#include <stdio.h>

void sort(int arr[], int n) {
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
    int n1, n2;
    
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements for first array: ", n1);
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements for second array: ", n2);
    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int merge[n1 + n2];

    for(int i = 0; i < n1; i++)
        merge[i] = arr1[i];
    for(int i = 0; i < n2; i++)
        merge[n1 + i] = arr2[i];

    sort(merge, n1 + n2);

    printf("\nMerged array in descending order:\n");
    for(int i = 0; i < n1 + n2; i++)
        printf("%d ", merge[i]);

    return 0;
}
