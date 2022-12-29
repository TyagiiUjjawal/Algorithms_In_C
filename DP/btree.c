#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define t 2
struct Btree{
    int n;
    int keys[2*t];
    struct Btree* child[2*t+1];
    bool leaf;
};
struct Btree* queue[100];
int top=-1;
struct Btree* pop()
{
   struct Btree* temp=queue[0];
   for(int i=0;i<=top;i++)
    queue[i]=queue[i+1];
   top--;
   return temp;
}
void push(struct Btree* newn)
{
    top++;
    queue[top]=newn;
}
bool isEmpty()
{
    if(top==-1) return true;
    else return false;
}
void LevelOrder(struct Btree* root)
{
    push(root);
    while(!isEmpty())
    {
        struct Btree* temp=pop();
        int i=1;
        while(i<=temp->n)
        {

            printf("%d ",temp->keys[i]);
            i++;
        }
        printf("    ");
        i=1;
        while(i<=(temp->n)+1)
        {
        if(temp->leaf==false)
        {
          push(temp->child[i]);
        }
            i++;

        }

    }


}
bool search(struct Btree* root,int key)
{
    int i=1;
    while(i<=root->n&&root->keys[i]<key)
    {

        i++;
    }
    if(i<=root->n&&key==root->keys[i]) return true;
    else if(root->leaf) return false;
    else
    {
        search(root->child[i],key);
    }

}
struct Btree* create()
{
    struct Btree* x=(struct Btree*)malloc(sizeof(struct Btree)*1);
    x->leaf=true;
    x->n=0;
    return x;
}
void split_child(struct Btree* x,int i)
{
    struct Btree* z=(struct Btree*)malloc(sizeof(struct Btree)*1);
    struct Btree* y=x->child[i];
    z->leaf=y->leaf;
    z->n=t-1;
    for(int j=1;j<=t-1;j++)
       z->keys[j]=y->keys[j+t];
    if(y->leaf==false)
    {
        for(int j=1;j<=t;j++)
            z->child[j]=y->child[j+t];
    }
    y->n=t-1;
    for(int j=x->n+1;j>=i+1;j--)
    {
        x->child[j+1]=x->child[j];
    }
    x->child[i+1]=z;
    for(int j=x->n;j>=i;j--)
    {
        x->keys[j+1]=x->keys[j];
    }
    x->keys[i]=y->keys[t];
    x->n=(x->n)+1;

}
struct Btree* insert(struct Btree* root,int k)
{
    struct Btree* r=root;
    if(r->n==2*t-1)
    {
        struct Btree* newroot=(struct Btree*)malloc(sizeof(struct Btree)*1);
        root=newroot;
        newroot->leaf=false;
        newroot->n=0;
        newroot->child[1]=r;
        split_child(newroot,1);
        insert_non_full(newroot,k);

    }
   else insert_non_full(root,k);
   return root;
}

void insert_non_full(struct Btree* x,int k)
{
    int i=x->n;
    if(x->leaf)
    {
        while(i>=1&&k<x->keys[i])
        {
            x->keys[i+1]=x->keys[i];
            i--;
        }
        x->keys[i+1]=k;
        x->n=(x->n)+1;
    }
    else
    {
        while(i>=1&&k<x->keys[i])
            i--;
        i++;
        if(x->child[i]->n==2*t-1)
          {
              split_child(x,i);
              if(k>x->keys[i])
                i=i+1;
          }
              insert_non_full(x->child[i],k);


    }
}

int main()
{
   struct Btree *root=create();
   while(1)
   {
       printf("\nEnter value to be inserted::(1 if you don't want to insert):");
       int c;
       scanf("%d",&c);

       if(c==-1) break;
       root=insert(root,c);

   }
   printf("\nLevel order traversal of final tree::");
   LevelOrder(root);

}