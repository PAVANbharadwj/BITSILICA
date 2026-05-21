#include<stdio.h>
#include<ctype.h>

int main()
{
    char filename[10],temp[]="temp.txt";
    printf("enter filename: ");
    scanf("%s",filename);
    FILE *fp,*ft;
    fp=fopen(filename,"r");
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
       int newword=1;
    while((ch=getc(fp)) != EOF)
    {
        if(newword && isalpha(ch))
        {
           ch=toupper(ch);
            newword=0;
        }
        else if(ch ==' '|| ch == '\n' || ch == '\t')
        {
            newword=1;
        }
        putc(ch,ft);
    }
    fclose(fp);
    fclose(ft);

    remove(filename);
    rename(temp,filename);
    printf("data modified");

}