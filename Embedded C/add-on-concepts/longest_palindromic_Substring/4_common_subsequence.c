#include <stdio.h>
#include <string.h>

int LCS(char *s1, char *s2) 
{
    int m = strlen(s1), n = strlen(s2);
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main() 
{
    char s1[]="abcde", s2[]="ace";
    printf("Longest Common Subsequence length = %d\n", LCS(s1, s2));
}
