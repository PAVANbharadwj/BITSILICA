#include<stdio.h>
int main()
{
    char str[]="\nworking on file handling..!";
    FILE*fp=fopen("shiva.txt","a");
    if(fp == NULL)
    {
    printf("error while opening file");
    }
    else
    {
        int index=0;
       /* while(str[index] != '\0')
        {
            fputc(str[index],fp);
            printf("%c",str[index]);
            index++;
        }
        
           int code;
           while((code=getc(fp)) != EOF)
           {
            printf("%c : %d\n",code,code);
           }
            */
           fputs(str,fp);

    }
    fclose(fp);
}