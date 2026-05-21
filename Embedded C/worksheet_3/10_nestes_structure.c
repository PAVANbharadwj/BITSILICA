#include <stdio.h>

struct Address
{
    char city[20];
    char state[20];
    int pincode;
};

struct Student 
{
    char name[20];
    int age;
    struct Address addr; 
};

int main() 
{
    struct Student s;

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter city: ");
    scanf("%s", s.addr.city);

    printf("Enter state: ");
    scanf("%s", s.addr.state);

    printf("Enter pincode: ");
    scanf("%d", &s.addr.pincode);

    printf("\n----- Student Details -----\n");
    printf("Name      : %s\n", s.name);
    printf("Age       : %d\n", s.age);
    printf("City      : %s\n", s.addr.city);
    printf("State     : %s\n", s.addr.state);
    printf("Pincode   : %d\n", s.addr.pincode);

}