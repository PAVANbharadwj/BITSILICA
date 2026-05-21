#include<stdio.h>
#define debug
int main()
{
    #ifdef debug
    printf("debugging mode on\n");
    #endif
    printf("program is running successfully");
}