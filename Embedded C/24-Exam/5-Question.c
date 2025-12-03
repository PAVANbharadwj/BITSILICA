#include <stdio.h>

int main() {
    int n1, n2;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements for first array: ");
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements for second array: ");
    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int found;
    for(int i = 0; i < n2; i++) {
        found = 0;
        for(int j = 0; j < n1; j++) {
            if(arr2[i] == arr1[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("The first array is a subset of the second array.");
            return 0;
        }
    }

    printf("The second array is a subset of the first array.");
    return 0;
}
