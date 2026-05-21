#include<stdio.h>
typedef struct dob
{
    int day:8;
    int month:4;
    int year:15;
}node;

int main()
{
    node dob;
    int d,m,y;
    printf("enter day\n");
    scanf("%d",&d);
    printf("enter month\n");
    scanf("%d",&m);
    printf("enter year\n");
    scanf("%d",&y);

    dob.day=d;
    dob.month=m;
    dob.year=y;


    printf("%d/%d/%d",dob.day,dob.month,dob.year);
}