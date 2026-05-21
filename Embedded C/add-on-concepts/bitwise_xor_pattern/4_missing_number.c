#include <stdio.h>

int missing(int arr[], int n) 
{
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++)
        xor1 ^= arr[i];

    for (int i = 1; i <= n+1; i++)
        xor2 ^= i;

    return xor1 ^ xor2;
}

int main() 
{
    int arr[] = {1,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Missing Number = %d\n", missing(arr, n));
}
