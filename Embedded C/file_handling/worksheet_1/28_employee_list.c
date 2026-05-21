#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "employees.txt"
typedef struct 
{
    char name[50];
    int age;
} Employee;

void addEmployee()
{
    Employee emp;
    FILE *fp = fopen(FILE_NAME, "a");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Age: ");
    scanf("%d", &emp.age);

    fprintf(fp, "%s %d\n", emp.name, emp.age);
    fclose(fp);

    printf("Employee added (info saved in file)\n");
}

void displayEmployees()
{
    FILE *fp = fopen(FILE_NAME, "r");
    char line[100];

    printf("\n--- Employee List ---\n");

    if (!fp) 
    {
        printf("No employee file found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}

void updateEmployee()
{
    char name[50];
    int newAge;
    char line[100];
    int found = 0;

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) 
    {
        printf("File error.\n");
        return;
    }

    printf("Enter employee name to update: ");
    scanf("%s", name);
    printf("Enter new age: ");
    scanf("%d", &newAge);

    while (fgets(line, sizeof(line), fp))
    {
        char existingName[50];
        int existingAge;

        sscanf(line, "%s %d", existingName, &existingAge);

        if (strcmp(existingName, name) == 0) 
        {
            fprintf(temp, "%s %d\n", name, newAge);
            found = 1;
        } 
        else
        {
            fprintf(temp, "%s %d\n", existingName, existingAge);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Employee record updated.\n");
    else
        printf("Employee not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n  MENU \n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Update Employee\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
