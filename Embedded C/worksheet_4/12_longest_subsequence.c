#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,0,9,10,11,12,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxLen = 1;       
    int currLen = 1;      
    int start = 0;         
    int currStart = 0;     

    for(int i = 0; i < n-1; i++) 
    {
        if(arr[i+1] > arr[i])
        {
            currLen++;
        } 
        else
        {
            currLen = 1;
            currStart = i+1;
        }

        if(currLen > maxLen) 
        {
            maxLen = currLen;
            start = currStart;
        }
    }

    printf("Length of longest continuous increasing subsequence: %d\n", maxLen);

    printf("Subsequence: ");
    for(int i = start; i < start + maxLen; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
