#include<stdio.h>
struct stu
{
int ssemarks;
    union next{
        int diplamomarks;
        int intermarks;
    }u;
    int bemarks;
};
int main()
{
    struct stu v;
    v.ssemarks=100;
    v.u.intermarks=90;
    v.bemarks=70;
    printf("sse marks:%d\ninter marks%d\nbe marks%d",v.ssemarks,v.u.intermarks,v.bemarks);
    printf("\nsize if structure: %d",sizeof(struct stu));
}