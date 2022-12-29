#include<stdio.h>

int max(int a, int b);

int lcs( char *X, char *Y, int m, int n, int **dp)
{
if (m == 0 || n == 0)
	return 0;

    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    int ans=0;
if (X[m-1] == Y[n-1])
	ans =  1 + lcs(X, Y, m-1, n-1,dp);
else
	ans =max(lcs(X, Y, m, n-1,dp), lcs(X, Y, m-1, n,dp));

    return dp[m][n]=ans;


}


int max(int a, int b)
{
	return (a > b)? a : b;
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
      int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    printf("%d", lcs(x, y, m, n,dp));

return 0;
}
