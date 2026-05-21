#include<stdio.h>
#include<string.h>
struct employee
{
    char name[20];
    union 
    {
        int salary;
        int wage;
    }u;
}v;
int main()
{
    char n[20];
    int num;
    printf("enter the name: ");
    scanf("%s",&n);
    strcpy(v.name,n);
    printf("\nenter 1 for salary mode\nenter 2 for wage mode");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
                printf("enter the salary");
                scanf("%d",&v.u.salary);
                break;
        case 2:
                printf("enter the wage");
                scanf("%d",&v.u.wage);
                printf("wage employee");
                break;
    }
    printf("employee name: %s\n %d",v.name,v.u.salary);
}
