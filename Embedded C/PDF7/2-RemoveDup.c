#include<stdio.h>

int dup(int *arr, int n){
    int *ptr = arr;
    int n2 = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < n2; j++) {
            if (*(ptr + i) == *(ptr + j)) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            *(ptr + n2) = *(ptr + i);
            n2++;
        }
    }
    return n2;
}

int main(){
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int len = dup(arr, n);
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < len; i++){
        printf("%d ", *(arr + i));
    }
    return 0;
}