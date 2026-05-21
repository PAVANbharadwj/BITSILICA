#include <stdio.h>
void findTwoUnique(int arr[], int n)
{
    int xor = 0;

    for (int i = 0; i < n; i++)
        xor ^= arr[i];

    int rightBit = xor & -xor;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] & rightBit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    printf("Unique numbers: %d and %d\n", x, y);
}

int main() 
{
    int arr[] = {2,4,7,9,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTwoUnique(arr, n);
}