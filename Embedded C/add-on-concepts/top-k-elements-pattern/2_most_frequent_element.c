#include <stdio.h>
int main()
{
    int arr[] = {1,1,1,2,2,3};
    int n = 6, k = 2;
    int freq[10] = {0};

    for(int i=0;i<n;i++)
        freq[arr[i]]++;

    printf("Top %d frequent numbers: ", k);

    for(int count=3; count>0 && k>0; count--) 
    { 
        for(int i=0; i<10; i++) 
        {
            if(freq[i] == count && k>0) 
            {
                printf("%d ", i);
                k--;
            }
        }
    }
}
