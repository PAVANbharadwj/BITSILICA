#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
     return (*(int*)a - *(int*)b); 
}

int main()
{
    int arr[] = {7,10,4,3,20,15};
    int n=6, k=3;

    qsort(arr, n, sizeof(int), compare);

    printf("Top %d smallest: ", k);
    for(int i=0;i<k;i++)
        printf("%d ", arr[i]);
}