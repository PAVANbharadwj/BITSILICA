#include <stdio.h>

void Subsequence(int arr[], int n) {
    int maxLen = 1, currLen = 1;
    int startIndex = 0, maxStartIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStartIndex = startIndex;
            }
            currLen = 1;
            startIndex = i;
        }
    }

    if (currLen > maxLen) {
        maxLen = currLen;
        maxStartIndex = startIndex;
    }

    printf("Longest increasing contiguous subsequence:\n");
    for (int i = maxStartIndex; i < maxStartIndex + maxLen; i++) {
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
