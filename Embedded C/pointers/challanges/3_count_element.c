#include <stdio.h>
int count_elements(int *start, int *end)
{
    return end - start; 
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = count_elements(arr, arr + 5);
    printf("Number of elements: %d\n", n);
}
