#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int day;
    int month;
    int year;
}node;

void collectdata(node*a)
{
    printf("enter date: ");
    scanf("%d",&a->day);
    printf("enter month: ");
    scanf("%d",&a->month);
    printf("enter year: ");
    scanf("%d",&a->year);

}

void printdata(node*a)
{
    printf("%d/%d/%d",a->day,a->month,a->year);
    //printf("month: %d\n",a->month);
    //printf("year: %d\n",a->year);
}
void difference(node*a,node*b)
{
    node c;
    c.day=abs(a->day - b->day);
    c.month=abs(a->month - b->month);
    c.year=abs(a->year - b->year);
    printf("the difference is: ");
    printdata(&c);
}

int main()
{
    node a,b;
    printf("enter first dob\n");
    collectdata(&a);
    printf("enter second dob\n");
    collectdata(&b);
   difference(&a,&b);
}
