#include <stdio.h>
#include<stdlib.h>
int graph[20][20];

void insert(int n)
{
  for(int i=0;i<n;i++)
  {
     printf("Enter total number of adjacency vertices of %d::",i);
     int m;
     scanf("%d",&m);
     for(int j=0;j<m;j++)
     {
         int ind;
         scanf("%d",&ind);
         graph[i][ind]=1;
     }
  }
}
int totalNoedges()
{
    int count=0;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
            if(graph[i][j]==1) count++;
    }
    return count;
}
int highNoedges()
{
    int count=0;
    int max=0;
    for(int i=0;i<20;i++)
    {
        int d=0;
        for(int j=0;j<20;j++)
            if(graph[i][j]==1)
            {
                d++;

            }
            if(count<d)
            {
                count=d;
                max=i;
            }
    }
    return max;
}
int minIncEdges(int n)
{
    int count=INT_MAX;
    int res=0;
    for(int j=0;j<n;j++)
    {
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(graph[i][j]==1) d++;
        }
        if(d<count)
        {
            count=d;
            res=j;
        }
    }
    return res;
}
int noIncEdges(int n)
{

    int res=-1;
    for(int j=0;j<n;j++)
    {
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(graph[i][j]==1) d++;
        }
        if(d==0)
        {

            res=j;
        }
    }
    return res;
}
int connWallEdges(int n)
{

    int res=-1;
    for(int i=0;i<n;i++)
    {
        int d=0;
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1) d++;
        }
        if(d==n)
        {

            res=i;
        }
    }
    return res;
}
int main()
{
    printf("Enter number of vertices's of graph");
    int n;
    scanf("%d",&n);
for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
            graph[i][j]=0;
    }
    insert(n);
    printf("Total number of edges: %d",totalNoedges());
    printf("\nVertex with highest number of adjacent: %d",highNoedges());
    printf("\nVertex with minimum number of incoming edges: %d",minIncEdges(n));
    printf("\nVertex with no incoming edges: %d",noIncEdges(n));
    printf("\nVertex which have connection with all vertices: %d",connWallEdges(n));


}