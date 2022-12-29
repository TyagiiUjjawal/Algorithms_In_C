#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define INT_MAX 292929929;
struct edge_node
{
    int vertex;
    int wt;
    struct edge_node* next;
};
struct vertex_node
{
    int prec;
    int dist;
    struct edge_node* adj_ptr;
};
struct vertex_node graph[51];
int stack[100];
int S_top=-1;
bool visited[100];
void S_push(int x)
{
    S_top++;
    stack[S_top]=x;
}
int S_pop()
{
    int v=stack[S_top];

    S_top--;
    return v;
}
bool isSEmpty()
{
    if(S_top==-1) return true;
    else return false;
}
void TopoSort(struct edge_node* head,int i,bool visited[])
{
    visited[i]=true;

    struct edge_node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp->vertex]==false)
            {
                TopoSort(graph[temp->vertex].adj_ptr,temp->vertex,visited);
            }
        temp=temp->next;
    }
    S_push(i);
}
void print(struct edge_node* head)
{
    struct edge_node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->vertex);
        temp=temp->next;
    }
}
struct edge_node* insert(struct edge_node *head,int x,int w)
{
    struct edge_node* newnode=(struct edge_node*)malloc(sizeof(struct edge_node)*1);
    newnode->next=NULL;
    newnode->vertex=x;
    newnode->wt=w;
    if(head==NULL) return newnode;
    else
    {
        newnode->next=head;
        head=newnode;
        return newnode;
    }
}
int main()
{
    printf("Enter Number of Vertices::\n");
    int ve;
    scanf("%d",&ve);
    for(int i=1;i<=ve;i++)
    {
        graph[i].prec=-1;
        graph[i].dist=INT_MAX;
        graph[i].adj_ptr=NULL;
    }
    for(int i=0; i<100; i++)
    visited[i]=false;
    printf("\nEnter source vertex::");
    int s;
    scanf("%d",&s);
    graph[s].dist=0;
    for(int i=1;i<=ve;i++)
    {
        printf("Enter adjacent of %d::\n",i);
        while(1)
        {
            printf("Enter Vertex::\n");
            int c;
            scanf("%d",&c);
            if(c==-1) break;
            else
            {
            int w;
            printf("Enter weight of %d-%d::\n",i,c);
            scanf("%d",&w);
                graph[i].adj_ptr=insert(graph[i].adj_ptr,c,w);
            }
        }
    }
        for(int i=1;i<=ve;i++)
        {
           if(visited[i]==false)
                TopoSort(graph[i].adj_ptr,i,visited);
        }
        int arr[ve+1];
        int j=1;
        while(!isSEmpty())
        {
            int res=S_pop();
            arr[j++]=res;
        }
        for(int i=1;i<=ve;i++)
        {
            int u=arr[i];
            if(graph[u].dist==INT_MAX) continue;
            struct edge_node* temp=graph[u].adj_ptr;
            while(temp!=NULL)
            {
               int v=temp->vertex;
               if(graph[v].dist>temp->wt+graph[u].dist)
               {
                   graph[v].dist=temp->wt+graph[u].dist;
               }
               temp=temp->next;
            }
        }

    printf("Resultant Minimum distances of vertices from given %d source::\n",s);
    for(int i=1;i<=ve;i++)
    {
        if(graph[i].dist==INT_MAX) printf("%d --> INFINITY\n",i);
       else  printf("%d --> %d\n",i,graph[i].dist);
    }


}