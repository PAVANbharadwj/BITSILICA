#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int intA = **(int **)a;
    int intB = **(int **)b;
    return intA - intB;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));         
    int **ptrArr = malloc(n * sizeof(int *));  
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        ptrArr[i] = &arr[i]; 
        }
    qsort(ptrArr, n, sizeof(int *), compare);
    printf("Sorted values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *ptrArr[i]);
    }
    printf("\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *ptrArr[i];
    }
    float avg = (float)sum / n;
    printf("Average = %.2f\n", avg);
    free(arr);
    free(ptrArr);
    return 0;
}
