#include<stdio.h>
int main()
{
    char filename[20];
    printf("enter filename: ");
    scanf("%s",filename);
    FILE*fp=fopen(filename,"r");
    char ch;
    int count=0;

    while((ch=getc(fp)) != EOF)
    {
        putchar(ch);
        if(ch == '\n')
        count++;
    }
    count=count+1;
    
    if(count==0)
    count=1;
    printf("\nno of lines in the file is %d",count);
    fclose(fp);

}
