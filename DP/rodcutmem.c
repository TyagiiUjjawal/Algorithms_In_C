#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int Rod_Cut_Memo(int profit[],int n,int memo[])
{
    if(memo[n]!=-1) return memo[n];
    if(n==0) {
        memo[0]=0;
        return 0;
    }
    int max_rev=profit[n];
    for(int i=1;i<=n;i++)
    {
        int rec_val=Rod_Cut_Memo(profit,n-i,memo);
        if(max_rev<profit[i]+rec_val)
          max_rev=profit[i]+rec_val;

    }
    memo[n]=max_rev;
    return max_rev;
}

int main()
{
    int n;
    printf("Enter length of rod::\n");
    scanf("%d",&n);
    int profit[n+1];
    int memo[n+1];
    profit[0]=0;
    for(int i=0;i<=n;i++)
        memo[i]=-1;
    printf("Enter profit for corresponding sizes::");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Maximum profit is %d",Rod_Cut_Memo(profit,n,memo));
}