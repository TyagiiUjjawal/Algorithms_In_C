#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int sol[100][100];
bool isSafe(int r,int c,int n)
{
    for(int i=0;i<c;i++)
    {
        if(sol[r][i])
            return false;
    }
    for(int i=r,j=c;j>=0&&i>=0;i--,j--)
        {if(sol[i][j])
        return false;}
    for(int i=r,j=c;j>=0&&i<n;i++,j--)
       {
           if(sol[i][j])
        return false;
       }

    return true;
}
bool solve(int col,int n)
{
    if(col==n) return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col,n))
        {
            sol[i][col]=1;
            if(solve(col+1,n))
                return true;
            sol[i][col]=0;
        }

    }
    return false;
}
int main()
{
    printf("Enter Number of Queens::");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sol[i][j]=0;
    }

    if(solve(0,n))
    {
        printf("\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",sol[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("Arrangement is not possible");
    }


}