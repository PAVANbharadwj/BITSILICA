#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int *arr = NULL;
    int size = 0;      
    int choice, element;
    while(1)
        {
        printf("\n=== Dynamic Array Menu ===\n");
        printf("1. Add Element\n");
        printf("2. Display Elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    if (choice == 1) {
            printf("Enter element to add: ");
            scanf("%d", &element);
            size++;
            arr = (int *)realloc(arr, size * sizeof(int));
            if (arr == NULL)
            {
                printf("Memory allocation failed!\n");
                return 1;
            }
            arr[size - 1] = element;
            printf("Element added successfully!\n");
        } 
        else if (choice == 2) {
            if (size == 0) {
                printf("Array is empty!\n");
            } else {
                printf("Array elements: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        } 
        else if (choice == 3) {
            free(arr);
            printf("Memory freed");
            break;
        } 
        else
        {
            printf("Invalid choice\n");
        }
    }
}