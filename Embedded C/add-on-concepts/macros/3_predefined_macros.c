#include<stdio.h>
int main()
{
    printf("date: %s\n",__DATE__);
    printf("time: %s\n",__TIME__);
    printf("file: %s",__FILE_NAME__);
}
