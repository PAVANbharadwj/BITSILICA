#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int left = 0, right = n - 1;

    while (left < right) {
        // Move left forward if it's already odd
        while (arr[left] % 2 == 1 && left < right)
            left++;

        // Move right backward if it's already even
        while (arr[right] % 2 == 0 && left < right)
            right--;

        if (left < right) {
            // Swap odd and even
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Print the result
    printf("Array after separating odd and even:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
