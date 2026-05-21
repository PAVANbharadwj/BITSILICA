#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
} Person;

int main()
{
    int n;
    
    printf("Enter number of people: ");
    scanf("%d", &n);

    Person arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter name for person %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter age for %s: ", arr[i].name);
        scanf("%d", &arr[i].age);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].age > arr[j].age) {
                Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted list (by age):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", arr[i].name, arr[i].age);
    }

    return 0;
}
