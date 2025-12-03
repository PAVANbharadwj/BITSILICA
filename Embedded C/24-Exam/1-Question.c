#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], freq[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; 
    }
    for(int i = 0; i < n; i++) {
        if(freq[i] != 0) {
            int count = 1;
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }
    int dupCount = 0;
    printf("\nElement\tFrequency\n");
    for(int i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d\t%d\n", arr[i], freq[i]);
            if(freq[i] > 1)
                dupCount++;
        }
    }

    printf("\nTotal duplicate elements = %d\n", dupCount);

    return 0;
}
