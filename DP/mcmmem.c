#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int memo[100][100];
int MCM_Rec(int start,int end,int p[])
{
    if(memo[start][end]>=0) return memo[start][end];
    if(end==start) {
        memo[start][end]=0;
        return 0;
    }
    int min_val=9999;
    for(int k=start;k<=end-1;k++)
    {
        int val=MCM_Rec(start,k,p)+MCM_Rec(k+1,end,p)+p[start-1]*p[k]*p[end];
        if(min_val>val)
            min_val=val;
    }
    memo[start][end]=min_val;
    return min_val;
}
int main()
{
    int n;
    for(int i=0;i<100;i++)
    {
       for(int j=0;j<100;j++)
            memo[i][j]=-1;

    }
    printf("Enter Number of matrices::\n");
    scanf("%d",&n);
    int p[n+1];
    printf("Enter corresponding orders::\n");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Minimum multiplication steps would be %d",MCM_Rec(1,n,p));
}