#include <stdio.h>
struct Normal 
{
    char a; 
    int  b;  
    char c;   
};
struct __attribute__((packed)) Packed
{
    char a;  
    int  b;   
    char c;   
};
int main()
{
    printf("Size of Normal struct : %lu bytes\n", sizeof(struct Normal));
    printf("Size of Packed struct : %lu bytes\n", sizeof(struct Packed));
}
