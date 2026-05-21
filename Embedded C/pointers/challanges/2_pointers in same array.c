#include <stdio.h>
int same_array(int *arr, int size, int *p1, int *p2)
 {
    if (p1 >= arr && p1 < arr + size && p2 >= arr && p2 < arr + size)
    {
        return 1;
    } else 
    {
        return 0;
    }
}
int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int x = 10;
    int *p1 = &arr[1];
    int *p2 = &arr[3]; 
    int *p3 = &x;       
    printf("%d\n", same_array(arr, 5, p1, p2)); 
    printf("%d\n", same_array(arr, 5, p1, p3));
}
