#include <stdio.h>
#include <string.h>

int isSubsequence(char *s1, char *s2)
{
    int i=0, j=0;
    while(s1[i] && s2[j]) 
    {
        if(s1[i] == s2[j])
        i++;
        j++;
    }
    return s1[i] == '\0';
}

int main()
{
    char s1[]="ace", s2[]="abcde";
    printf(isSubsequence(s1, s2) ? "YES\n" : "NO\n");
}
