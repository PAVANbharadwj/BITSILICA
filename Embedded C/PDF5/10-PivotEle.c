#include <stdio.h>

int findPivotIndex(int nums[], int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += nums[i];

    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum)
            return i;
        leftSum += nums[i];
    }
    return -1;  
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int pivot = findPivotIndex(nums, n);
    if (pivot != -1)
        printf("Pivot index is: %d\n", pivot);
    else
        printf("No pivot index found.\n");

    return 0;
}
