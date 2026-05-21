#include<stdio.h>
struct stu{
    char name[10];
    struct marks{
        int telugu;
        int english;
    }m;
    int total;
}s;
int main()
{
    printf("enter name of student: ");
    scanf("%s",s.name);
    printf("enter marks");
    scanf("%d %d",&s.m.telugu,&s.m.english);
    s.total=s.m.telugu+s.m.english;
    printf("name: %s\ntelugu: %d\nenglish:%d\ntotal:%d",s.name,s.m.telugu,s.m.english,s.total);
}