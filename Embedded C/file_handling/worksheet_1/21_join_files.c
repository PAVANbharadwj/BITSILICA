#include<stdio.h>
#define filename "shiva.txt"
#define temp    "t.txt"
int main()
{
    char file[]="temp.txt";
   
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    FILE *ft = fopen(temp, "r");
    if(ft == NULL)
    {
        printf("Error creating temp file.\n");
        fclose(fp);
        return 0;
    }
    
    FILE *fr = fopen(file, "w");
    if(ft == NULL)
    {
        printf("Error creating temp file.\n");
        fclose(fp);
        return 0;
    }
    char ch;
    while((ch=getc(fp))!= EOF)
    {
        putc(ch,fr);
    }
    putc('\n',fr);
    while((ch=getc(ft))!= EOF)
    {
        putc(ch,fr);
    }
    
    fclose(ft);
    fclose(fp);
    fclose(fr);
    
    printf("data transferred");
}