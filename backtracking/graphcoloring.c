#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

int G[100][100];

int arr[100];


bool place(int k,int i)
{
    for (int  j = 1; j < k; j++)
    {
        if (G[k][j]==1 && arr[j] == i)
        {
            return false;
        }
    }
    return true;
}

void m_color(int k,int v,int m,int *check)
{
    for (int i = 1; i <= m ; i++)
    {
        if (place(k,i))
        {
            if (k == v)
            {
                arr[k] = i;
                *check = 1;
                return;
            }
            else
            {
                arr[k] = i;
                m_color(k+1,v,m,check);
                if (*check == 1)
                {
                    break;
                }
            }
        }
    }
}


int main()
{
    int v;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&v);
    for (int i = 1; i <= v; i++)
    {
        printf("\nEnter the adjacency vettices for vertex %d : \n",i);
        for (int j = 1; j < v+1; j++)
        {
            int c;
            printf("\nEnter 1 if %d have connection with %d or enter 0 : ",j,i);
            scanf("%d",&c);
            G[i][j] = c;
        }
    }
    int m;
    printf("\nEnter the total number of colors : ");
    scanf("%d",&m);
    int check = 0;
    m_color(1,v,m,&check);
    for (int i = 1; i < v+1; i++)
    {
        printf("\n%d has color %d",i,arr[i]);
    }
    return 0;
}