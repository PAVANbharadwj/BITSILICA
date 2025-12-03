#include<stdio.h>

void mergeSortedArrays(int a[], int n1, int b[], int n2, int merged[]) {
        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2) {
            if(a[i] < b[j])
                merged[k++] = a[i++];
            else
                merged[k++] = b[j++];
        }
        while(i < n1)
            merged[k++] = a[i++];
        while(j < n2)
            merged[k++] = b[j++];
}

int main(){
    int n1,n2;
    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d sorted elements for first array:\n", n1);
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d sorted elements for second array:\n", n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int merged[n1 + n2];
    mergeSortedArrays(arr1, n1, arr2, n2, merged);
    printf("Merged and sorted array:\n");
    for(int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
}