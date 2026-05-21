#include <stdio.h>

int main() {
    char *q = "main(){char*q=%c%s%c;printf(q,34,q,34);}";

    printf(q, 34, q, 34);
}
