#include<stdio.h>
#include<stdlib.h>
int main()
{   
    char *str=NULL;
    char ch;
    int size=0;
    printf("enter the characters");
    while((ch=getchar())!='\n')
    {
        str=realloc(str,(size+1)*sizeof(char));
        str[size]=ch;
        size++;
    }
    str=realloc(str,(size+1)*sizeof(char));
    str[size]='\0';
    puts(str); 
    free(str);
}