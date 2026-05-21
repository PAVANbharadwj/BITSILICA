#include<stdio.h>
int main()
{
    FILE *fptr=NULL;
    fptr=fopen("shiva.txt","r");
    if(fptr == NULL)
    {
        printf("file opening failed");
    }
    else
    {
        printf("file opened successfully\n");

    }
    fclose(fptr);
}