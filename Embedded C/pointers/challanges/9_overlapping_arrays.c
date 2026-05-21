#include <stdio.h>
void findOverlap(int *arr1, int size1, int *arr2, int size2)
{
    int *p1, *p2;
    int found = 0;
    printf("Overlapping elements: ");
    for (p1 = arr1; p1 < arr1 + size1; p1++)
    {
        for (p2 = arr2; p2 < arr2 + size2; p2++)
        {
            if (*p1 == *p2)
            {
                printf("%d ", *p1);
                found = 1;
                break;
            }
        }
    }
    if (!found)
        printf("None");

        printf("\n");
}
int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {3, 4, 5, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    findOverlap(arr1, size1, arr2, size2);
}
