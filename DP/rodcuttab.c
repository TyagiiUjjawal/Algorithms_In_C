#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int Rod_Cut_DP(int profit[],int n,int dp[])
{
    dp[0]=0;
    for(int j=1;j<=n;j++)
    {
    int max_rev=-1;
    for(int i=1;i<=j;i++)
    {
        if(max_rev<profit[i]+dp[j-i])
            max_rev=profit[i]+dp[j-i];
    }
    dp[j]=max_rev;

    }
    return dp[n];
}
int main()
{
    int n;
    printf("Enter length of rod::\n");
    scanf("%d",&n);
    int profit[n+1];
    int dp[n+1];
    profit[0]=0;
    printf("Enter profit for corresponding sizes::");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Maximum profit is %d",Rod_Cut_DP(profit,n,dp));
}