#include <stdio.h>

int findDuplicate(int arr[], int n) 
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i]]) 
        {
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        } 

        else
        {
            if (i != arr[i]) return arr[i];
            i++;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {1,3,4,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Duplicate Number = %d\n", findDuplicate(arr, n));
}
