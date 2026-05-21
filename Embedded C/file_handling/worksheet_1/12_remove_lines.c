#include<stdio.h>
int main()
{
    char filename[20],temp[]="text.txt";
    printf("enter filename : ");
    scanf("%s",filename);
    
    FILE*fp=fopen(filename,"r");
    if(fp == NULL)
    {
        printf("error while opening file");
    }
    
    int line,cline=1;
    printf("enter the line you need to delete ");
    scanf("%d",&line);
    char ch;
    
    FILE*ft=fopen(temp,"w");
    if(ft == NULL)
    {
        printf("error while opening file");
    }
    
    while((ch=getc(fp)) != EOF)
    {
        if(line != cline)
        putc(ch,ft);

        if(ch=='\n')
        cline++;
    }
    fclose(ft);
    fclose(fp);

    remove(filename);
    rename(temp,filename);
    printf("line removed");
}