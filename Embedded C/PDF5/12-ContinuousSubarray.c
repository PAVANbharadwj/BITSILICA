#include <stdio.h>

void Subsequence(int arr[], int n) {
    if (n == 0) {
        printf("Empty array\n");
        return;
    }

    int maxLen = 1, currLen = 1;
    int start = 0, maxStart = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = start;
            }
            currLen = 1;
            start = i;
        }
    }
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = start;
    }

    printf("Longest Continuous Increasing Subsequence: ");
    for (int i = maxStart; i < maxStart + maxLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nLength = %d\n", maxLen);
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    Subsequence(arr, n);
    return 0;
}
