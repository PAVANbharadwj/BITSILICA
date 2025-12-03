#include <stdio.h>
struct Date {
    unsigned int day   : 5; 
    unsigned int month : 4;  
    unsigned int year  : 12; 
};

int main() {
    struct Date today;
    today.day = 18;
    today.month = 7;
    today.year = 2025;
    printf("Date: %02u-%02u-%04u\n", today.day, today.month, today.year);

    return 0;
}
