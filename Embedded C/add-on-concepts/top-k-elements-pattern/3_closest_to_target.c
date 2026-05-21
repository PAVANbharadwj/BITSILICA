#include <stdio.h>
#include <stdlib.h>

int x = 7;

int compare(const void *a, const void *b) 
{
    return abs(*(int*)a-x) - abs(*(int*)b-x);
}

int main() 
{
    int arr[] = {5,6,7,8,9};
    int n = 5, k = 3;

    qsort(arr, n, sizeof(int), compare);

    printf("Closest %d numbers: ", k);
    for(int i=0; i<k; i++)
        printf("%d ", arr[i]);
}