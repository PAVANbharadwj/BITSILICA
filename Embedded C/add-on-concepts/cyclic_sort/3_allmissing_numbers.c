#include <stdio.h>
void findMissing(int arr[], int n)
{
    int i = 0;
    while (i < n) 
    {
        int correct = arr[i] - 1;
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[correct])
        {
            int temp = arr[i];
            arr[i] = arr[correct];
            arr[correct] = temp;
        } 
        else
        {
            i++;
        }
    }
    printf("Missing Numbers: ");
    for (i = 0; i < n; i++) 
    {
        if (arr[i] != i + 1)
            printf("%d ", i + 1);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {4,3,2,7,8,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findMissing(arr, n);
}