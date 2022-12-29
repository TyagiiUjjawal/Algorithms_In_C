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
    int parent;
    bool inPQ;
    int PQ_indx;
    struct edge_node* adj_ptr;
};
struct vertex_node graph[51];
struct PQ_node
{
    int vertex;
    int key;
};
struct PQ_node PQ[51];
int n=1;
void swap(struct PQ_node *a,struct PQ_node *b)
{
   struct PQ_node temp=*a;
   *a=*b;
   *b=temp;
   int tempIndx=graph[a->vertex].PQ_indx;
   graph[a->vertex].PQ_indx=graph[b->vertex].PQ_indx;
   graph[b->vertex].PQ_indx=tempIndx;

}
void heapify(int v,int i)
{
    int Rchild=2*i,Lchild=2*i+1,min=i;
    if(Rchild<=v&&PQ[Rchild].key<PQ[min].key)
        min=Rchild;
    if(Lchild<=v&&PQ[Lchild].key<PQ[min].key)
        min=Lchild;
    if(min!=i)
    {
       swap(&PQ[min],&PQ[i]);

       heapify(v,min);
    }

}
struct PQ_node extract_min()
{
   struct PQ_node temp=PQ[1];
   PQ[1]=PQ[n];
   n=n-1;
   heapify(n,1);
   return temp;
}
void decrease_key(int i,int k)
{
    PQ[i].key=k;
    while(i!=1&&PQ[i/2].key>PQ[i].key)
    {
        swap(&PQ[i/2],&PQ[i]);
        i=i/2;
    }
}
void build_minheap(int v)
{
    for(int i=(v-1)/2;i>=1;i--)
    {
        heapify(v,i);
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
void print(struct edge_node* head)
{
    struct edge_node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->vertex);
        temp=temp->next;
    }
}
int main()
{
    printf("Enter Number of Vertices::\n");
    int v;
    scanf("%d",&v);
    n=v;
    for(int i=1;i<=v;i++)
    {
        graph[i].parent=-1;
        graph[i].inPQ=true;
        graph[i].PQ_indx=i;
        graph[i].adj_ptr=NULL;
    }
    for(int i=1;i<=v;i++)
    {
        PQ[i].vertex=i;
        PQ[i].key=INT_MAX;
    }
    PQ[1].key=0; //assuming source vertex is 1
    build_minheap(v);
    for(int i=1;i<=v;i++)
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
                graph[c].adj_ptr=insert(graph[c].adj_ptr,i,w);
            }
        }
    }
    int res=0;
    while(n!=0)
    {
        struct PQ_node u=extract_min();
        res+=u.key;
        graph[u.vertex].inPQ=false;
        struct edge_node* temp=graph[u.vertex].adj_ptr;
        while(temp!=NULL)
        {
            int ve=temp->vertex;

            if(graph[ve].inPQ==true&&temp->wt<PQ[graph[ve].PQ_indx].key)
            {
                decrease_key(graph[ve].PQ_indx,temp->wt);
                graph[ve].parent=u.vertex;
            }
            temp=temp->next;
        }

    }

    printf("Resultant Minimum MST length is %d",res);


}