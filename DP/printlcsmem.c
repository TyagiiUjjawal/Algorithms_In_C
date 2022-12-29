#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}
int dp[5][4];


int lcs( char *X, char *Y, int m, int n)
{
if (m == 0 || n == 0)
	return 0;

    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    int ans=0;
if (X[m-1] == Y[n-1])
	ans =  1 + lcs(X, Y, m-1, n-1);
else
	ans =max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));

    dp[m][n]=ans;
    dp[m][n];
}




int main()
{
        char x[]={'a','b','c','d'};
        char y[]={'a','f','b'};           
      for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=-1;
        }
      }
 
    printf(" count of lcs %d \n", lcs(x, y, 4,3));
        

    int index=dp[4][3];
    char lcsstring[index+1];
    lcsstring[index]='\0';
    int i=4;
    int j=3;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            lcsstring[index-1]=x[i-1];
            i--; j--; index--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
        
    }
    printf("the lcs is %s",lcsstring );

return 0;
}
