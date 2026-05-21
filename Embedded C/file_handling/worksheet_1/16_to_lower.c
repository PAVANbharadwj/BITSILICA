#include<stdio.h>
int main()
{
    char file[100],temp[]="temp.txt";
    printf("enter file name: ");
    scanf("%s",file);
    FILE *fp,*ft;
    fp=fopen(file,"r");
    if(fp == NULL)
    {
        printf("error while opening file");
        return 0;
    }
    ft=fopen(temp,"w");
    if(ft == NULL)
    {
        printf("error while opening file");
        return 0;
    }
    char ch;
    while((ch=getc(fp)) !=EOF)
    {
        if(ch>=65 && ch<=90)
        {
            ch=ch+32;
        }
        putc(ch,ft);
    }
    fclose(fp);
    fclose(ft);
    
    remove(file);
    rename(temp,file);
    printf("case changed"); 
}