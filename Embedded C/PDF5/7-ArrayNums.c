#include <stdio.h>
#include <stdlib.h>

void findNum(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0)
            arr[index] = -arr[index]; 
    }
    printf("Missing numbers: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findNum(arr, n);
    return 0;
}