#include<stdio.h>
#include<string.h>
void removeduplicates(char*ptr)
{
    for(int i=0;ptr[i] != '\0';i++)
    {
        for(int j=i+1;ptr[j] != '\0' ;j++)
        {
            if(ptr[i]==ptr[j])
            {
                memmove(ptr+j,ptr+j+1,strlen(ptr+j+1)+1);
                j--;
            }
        }

    }
    puts(ptr);
}
int main()
{
    char str[]="embedded";
    removeduplicates(str);
}