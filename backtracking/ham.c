#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int graph[100][100];
int x[100];
bool place(int xk,int k,int n)
{
    int a=x[k-1];
    if(graph[a][xk]!=1) return false;
    for(int j=1;j<k;j++)
    {
        if(x[j]==xk) return false;
    }
    if(k==n)
    {
         

        if(graph[xk][1]!=1) return false;

    }
    return true;
}

void HamilPath(int k,int n)
{
    for(int xk=1;xk<=n;xk++)
    {
        if(place(xk,k,n))
        {
            x[k]=xk;
            if(k==n)
            {  
 printf("\nPath is::\n");
    for(int i=0;i<n;i++)
        printf("%d ",x[i]);
                return;
            }
            else HamilPath(k+1,n);
        }
    }
}
void print(int n){
     printf("\nPath is::\n");
    for(int i=0;i<n;i++)
        printf("%d ",x[i]);
}
int main()
{
    printf("Enter Number of Verices::");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            graph[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter adjacent of %d::(-1 to if no more adj. are there)",i);
        while(1)
        {

            int v;
            scanf("%d",&v);
            if(v==-1)
                break;
            graph[i][v]=1;


        }


    }
    x[0]=1;
    HamilPath(1,n);
   print(n);

}
