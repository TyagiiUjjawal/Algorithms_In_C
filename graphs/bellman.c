#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
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
    int s;
    printf("Enter source::\n");
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
    for(int i=1;i<=ve-1;i++)
    {
        for(int u=1;u<=ve;u++)
        {
            struct edge_node* temp=graph[u].adj_ptr;
            while(temp!=NULL)
            {
                int v=temp->vertex;
                if(graph[v].dist>graph[u].dist+temp->wt)
                    graph[v].dist=graph[u].dist+temp->wt;
            temp=temp->next;
            }

        }

        }
        for(int u=1;u<=ve;u++)
        {
            struct edge_node* temp=graph[u].adj_ptr;
            while(temp!=NULL)
            {
                int v=temp->vertex;
                if(graph[v].dist>graph[u].dist+temp->wt)
                   {
                       printf("-ve Edge cycles are present::");
                       return 0;
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