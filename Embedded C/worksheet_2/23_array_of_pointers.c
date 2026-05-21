#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[30];
    char email[50];
    char mobile[15];
} Person;

int main()
{
    int n;

    printf("Enter number of persons: ");
    scanf("%d", &n);

    Person *arr[n];

    for (int i = 0; i < n; i++)
     {
        arr[i] = (Person *)malloc(sizeof(Person));
        
        printf("\nEnter details of person %d\n", i + 1);

        printf("Name: ");
        scanf("%s", arr[i]->name);

        printf("Email: ");
        scanf("%s", arr[i]->email);

        printf("Mobile: ");
        scanf("%s", arr[i]->mobile);
    }

 printf("\n");
    for (int i = 0; i < n; i++)
     {
        printf("\nPerson %d:\n", i + 1);
        printf("Name   : %s\n", arr[i]->name);
        printf("Email  : %s\n", arr[i]->email);
        printf("Mobile : %s\n", arr[i]->mobile);
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
}
