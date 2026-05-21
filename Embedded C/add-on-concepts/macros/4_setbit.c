#include<stdio.h>
#define setlsb(data) data|1

int main()
{
    printf("set lsb %d",setlsb(2));
}