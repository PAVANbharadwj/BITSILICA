#include <stdio.h>
#include <stdlib.h>


int compareInt(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);  
}

int main() 
{
    int arr[] = {50, 20, 40, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compareInt);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

}