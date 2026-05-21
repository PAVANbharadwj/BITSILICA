#include <stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int size, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}
void buildHeap(int heap[], int size) 
{
    for(int i = size/2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

void replaceTop(int heap[], int size, int val)
{
        heap[0] = val;
    heapify(heap, size, 0);
}

void kLargestElements(int arr[], int n, int k)
{
    int heap[k];

    for(int i=0; i<k; i++)
        heap[i] = arr[i];

    buildHeap(heap, k);

    for(int i=k; i<n; i++) 
    {
        if(arr[i] > heap[0])
        {
            replaceTop(heap, k, arr[i]);
        }
    }
    printf("Top %d largest elements: ", k);
    for(int i=0; i<k; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main()
{
    int arr[] = {3, 1, 5, 12, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    kLargestElements(arr, n, k);
}
