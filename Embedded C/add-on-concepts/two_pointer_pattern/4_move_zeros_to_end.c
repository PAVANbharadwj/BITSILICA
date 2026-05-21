#include<stdio.h>

void movezerostoend(int *ptr, int n)
{
    int left = 0;
    for(int right = 0; right < n; right++)
    {
        if(ptr[right] != 0)
        {
            ptr[left++] = ptr[right];
        }
    }

    while(left < n)
    {
        ptr[left++] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
}

int main()
{
    int arr[] = {1,0,3,0,1,0,9,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    movezerostoend(arr, n);
}
