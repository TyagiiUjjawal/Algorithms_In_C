#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
int hash(int key){
    return key%10;
}
void sortedinsert(struct node **h,int x){
    struct node *t,*q=NULL,*p=*h;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(*h==NULL){
        *h=t;
    }else{
        while(p && p->data<x){
            q=p;
            p=p->next;

        }
        if(p==*h){
            t->next=*h;
            *h=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

void insert(struct node *h[],int key){
    int i=hash(key);
    sortedinsert(&h[i],key);
}
struct node *search(struct node * p,int key){
    while(p){
        if(key==p->data)
        return p;
        else
        p=p->next;
    }
    return NULL;
}


    int main(){
        struct node * hashtable[10],*temp;
        int i;
        for(i=0;i<10;i++){
            hashtable[i]=NULL;
        }
        insert(hashtable,12);
        insert(hashtable,22);
        insert(hashtable,22);
        temp=search(hashtable[hash(21)],21);
        printf("%d",temp->data);
return 0;
}