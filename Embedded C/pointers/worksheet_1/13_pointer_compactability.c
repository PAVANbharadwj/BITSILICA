#include<stdio.h>
int main()
    {
        int num=10;
        int*ip=&num;
        float*fp;
        fp=(float*)ip;
        printf("%f",*fp);
    }