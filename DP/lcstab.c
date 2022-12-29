#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int LCS(char x[], char y[], int m, int n)
{
    int i, j;
    int lcs[m + 1][n + 1];
    if (m == 0 || n == 0)
    {
        return 0;
    }
    for (i = 0; i <= m; i++)
    {
        lcs[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        lcs[0][j] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i-1] == y[j-1])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                if (lcs[i - 1][j] < lcs[i][j - 1])
                {
                    lcs[i][j] = lcs[i][j - 1];
                }
                else
                {
                    lcs[i][j] = lcs[i - 1][j];
                }
            }
        }
    }

    return lcs[m][n];
}

int main()
{
    int m;
    scanf("%d", &m);
    char x[m];
    scanf("%s",x);
    int n;
    scanf("%d", &n);
    char y[n];
    scanf("%s",y);
    printf("%d", LCS(x, y, m, n));
}